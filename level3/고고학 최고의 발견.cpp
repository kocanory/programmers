#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;
vector<pair<int, int>> dir = {{0, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int n, m, answer = INT_MAX;

void rotate(int x, int y, int i, vector<vector<int>> &clockHands)
{
    for(auto d : dir)
    {
        if(x + d.first >= 0 && x + d.first < n && y + d.second >= 0 && y + d.second < m)
            clockHands[x + d.first][y + d.second] = (clockHands[x + d.first][y + d.second] + i) % 4;
    }
}

void counterRotate(int x, int y, int i, vector<vector<int>> &clockHands)
{
    for(auto d : dir)
    {
        if(x + d.first >= 0 && x + d.first < n && y + d.second >= 0 && y + d.second < m)
            clockHands[x + d.first][y + d.second] = (clockHands[x + d.first][y + d.second] - i + 4) % 4;
    }
}

bool check(vector<vector<int>> &clockHands)
{
    for(int i = 0;i < n;i++)
        for(int j =0;j <m;j++)
            if(clockHands[i][j] != 0)
                return false;
    return true;
}

void dfs(int x, int y, int count, vector<vector<int>> &clockHands)
{
    if(x == n)
    {
        if(check(clockHands))
            answer = min(answer, count);
        return;
    }
    for(int i = 0;i < 4;i++)
    {
        rotate(x, y, i, clockHands);
        if(x - 1 >= 0 && clockHands[x - 1][y] != 0)
        {
            counterRotate(x, y, i, clockHands);
            continue;
        }
        int nx = (y + 1 == m) ? x + 1 : x;
        int ny = (y + 1) % m;
        dfs(nx, ny, count + i, clockHands);
        counterRotate(x, y, i, clockHands);
    }
}

int solution(vector<vector<int>> clockHands) {
    n = clockHands.size();
    m = clockHands[0].size();
    dfs(0, 0, 0, clockHands);
    return answer;
}