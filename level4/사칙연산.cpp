#include <vector>
#include <string>
#include <climits>

using namespace std;

int dp[201][201][2];

int n;

int solution(vector<string> arr)
{
    n = arr.size();
    
    for(int i = 0;i < n;i += 2)
    {
        for(int j = 0;j < n;j += 2)
        {
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MIN;
        }
    }
    
    for(int i = 0;i < n;i += 2)
    {
        dp[i][i][0] = stoi(arr[i]);
        dp[i][i][1] = stoi(arr[i]);
    }
    
    for(int len = 3;len <= n;len += 2){
        for(int k = 1;k <= n - 2;k += 2){
            for(int i = max(k - (len - 2), 0) ; i <= k - 1; i += 2)
            {
                int j = i + len - 1;
                if(arr[k] == "-")
                {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][k - 1][0] - dp[k + 1][j][1]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i][k - 1][1] - dp[k + 1][j][0]);
                }
                else if(arr[k] == "+")
                {
                    dp[i][j][0] = min(dp[i][j][0], dp[i][k - 1][0] + dp[k + 1][j][0]);
                    dp[i][j][1] = max(dp[i][j][1], dp[i][k - 1][1] + dp[k + 1][j][1]);
                }
            }
        }
    }
    
    return dp[0][n - 1][1];
}