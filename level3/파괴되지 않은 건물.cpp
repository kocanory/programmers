#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int m = board.size(), n = board[0].size();
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));
    for(auto s : skill)
    {
        int start_x = s[1], start_y = s[2], end_x = s[3], end_y = s[4], type = 0, degree = s[5];
        
        if(s[0] == 1)
            type = -1;
        else if(s[0] == 2)
            type = 1;
        
        arr[start_x][start_y] += (type * degree);
        arr[start_x][end_y + 1] -= (type * degree);
        arr[end_x + 1][start_y] -= (type * degree);
        arr[end_x + 1][end_y + 1] += (type * degree);
    }
    
    for(int i = 0;i < m;i++)
    {
        for(int j = 1;j < n;j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    
    for(int j = 0; j < n;j++)
    {
        for(int i = 1;i < m;i++)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }
    
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            board[i][j] += arr[i][j];
            if(board[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}