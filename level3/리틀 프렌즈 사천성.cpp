#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> arr;
int row, col;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool check_inrange(int x, int y)
{
    return x >= 0 && x < row && y >= 0 && y < col;
}

bool solve(int x, int y)
{
    char c = arr[x][y];
    
    for(int i = 0;i < 4;i++)
    {
        int xpos = x + dx[i], ypos = y + dy[i];
        while(check_inrange(xpos, ypos) && (arr[xpos][ypos] == '.' || arr[xpos][ypos] == c))
        {
            if(arr[xpos][ypos] == c)
            {
                arr[x][y] = '.';
                arr[xpos][ypos] = '.';
                return true;
            }
            
            for(int j = 0;j < 4;j++)
            {
                if(i == j || (i != j && (i % 2 == j % 2))) continue;
                int nx = xpos + dx[j], ny = ypos + dy[j];
                while(check_inrange(nx, ny) && (arr[nx][ny] == '.' || arr[nx][ny] == c))
                {
                    if(arr[nx][ny] == c)
                    {
                        arr[x][y] = '.';
                        arr[nx][ny] = '.';
                        return true;
                    }
                    nx += dx[j];
                    ny += dy[j];
                }
            }
            xpos += dx[i];
            ypos += dy[i];
        }
    }
    return false;
}

string solution(int m, int n, vector<string> board) {
    string answer = "";
    row = m;
    col = n;
    
    arr = board;
    vector<pair<char, pair<int, int>>> reserve;
    map<char, int> alpha;
    
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(isalpha(arr[i][j]) && alpha[arr[i][j]] == 0)
            {
                alpha[arr[i][j]] = 1;
                reserve.push_back({arr[i][j], {i, j}});
            }
        }
    }
    sort(reserve.begin(), reserve.end());
    bool flag = true;
    while(flag)
    {
        flag = false;
        for(int i = 0;i < reserve.size();i++)
        {
            flag = solve(reserve[i].second.first, reserve[i].second.second);
            if(flag)
            {
                answer += reserve[i].first;
                reserve.erase(reserve.begin() + i);
                break;
            }
        }
    }
    return answer = (!reserve.empty() ? "IMPOSSIBLE" : answer);
}