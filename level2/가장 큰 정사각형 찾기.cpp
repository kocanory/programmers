#include <iostream>
#include<vector>
using namespace std;
int dp[1001][1001];
int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i = 1;i<board.size() + 1;i++)
    {
        for(int j = 1;j<board[0].size() + 1;j++)
        {
            if(board[i - 1][j - 1] == 1)
            {
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                if(answer < dp[i][j])
                    answer = dp[i][j];
            }
        }
    }
    

    return answer * answer;
}