#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> back;
    while(true)
    {
        bool flag = false;
        back = board;
        for(int i = 0;i < m - 1;i++)
        {
            for(int j = 0;j < n - 1;j++)
            {
                if(back[i][j] != '0' && back[i][j] == back[i][j + 1] && back[i][j] == back[i + 1][j] && back[i][j] == back[i + 1][j + 1])
                {
                    if(!flag) flag = true;
                    board[i][j] = '0';
                    board[i][j + 1] = '0';
                    board[i + 1][j] = '0';
                    board[i + 1][j + 1] = '0';
                }                    
            }
        }
        if(!flag) break;
        for(int i = m - 1;i>=0;i--)
        {
            for(int j = 0;j<n;j++)
            {
                if(board[i][j] == '0')
                {
                    for(int k = i - 1;k>=0;k--)
                    {
                        if(board[k][j] != '0')
                        {
                            char temp = board[k][j];
                            board[k][j] = board[i][j];
                            board[i][j] = temp;
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
            if(board[i][j] == '0')
                answer++;
    }
    return answer;
}