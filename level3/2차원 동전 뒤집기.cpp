#include <string>
#include <vector>

using namespace std;

int row, col, answer = 1e9;
vector<int> rows;

int coin_rev(vector<vector<int>> arr)
{
    int count = 0;
    for(auto r : rows)
    {
        for(int c = 0;c < col;c++)
            arr[r][c] = !arr[r][c];
        count++;
    }
    
    for(int c = 0;c < col;c++)
    {
        if(arr[0][c]) count++;
        for(int r = 1;r < row;r++)
            if(arr[r][c] != arr[0][c])
                return 1e9;
    }
    return count;
}

void dfs(int idx, vector<vector<int>> &arr)
{
    if(idx == row)
    {
        answer = min(answer, coin_rev(arr));
        return;
    }
    
    rows.push_back(idx);
    dfs(idx + 1, arr);
    rows.pop_back();
    dfs(idx + 1, arr);
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    row = beginning.size();
    col = beginning[0].size();
    
    vector<vector<int>> arr(row, vector<int>(col, 0));
    
    
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
            if(beginning[i][j] != target[i][j])
                arr[i][j] = 1;
    }
    dfs(0, arr);
    
    return answer = (answer == 1e9) ? -1 : answer;
}