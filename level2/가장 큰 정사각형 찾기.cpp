#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0, n = board.size(), m = board[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            if(board[i - 1][j - 1]){
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                answer = max(answer, dp[i][j]);
            }

    return answer * answer;
}