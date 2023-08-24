#include <string>
#include <vector>

using namespace std;

int zero = 0, one = 0;

bool check(int x, int y, int size, vector<vector<int>> &arr)
{
    int val = arr[x][y];
    for(int i = x; i < x + size;i++)
        for(int j = y; j < y + size;j++)
            if(arr[i][j] != val)
                return false;
    return true;
}

void dfs(int x, int y, int size, vector<vector<int>> &arr)
{
    if(check(x, y, size, arr))
    {
        if(arr[x][y] == 0)
            zero++;
        else
            one++;
        return;
    }
    size /= 2;
    dfs(x, y, size, arr);
    dfs(x, y + size, size, arr);
    dfs(x + size, y, size, arr);
    dfs(x + size, y + size, size, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    dfs(0, 0, arr.size(), arr);
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}