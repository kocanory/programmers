#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {    
    vector<vector<int>> dp(target + 1, vector<int>(2));
    for(int i = 0;i <= target;i++)
    {
        dp[i][0] = 1e9;
        dp[i][1] = -1e9;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for(int n = 0;n < target;n++)
    {
        for(int s = 1;s <= 20;s++)
        {
            if(n + s > target) break;
            if(dp[n + s][0] > dp[n][0] + 1)
            {
                dp[n + s][0] = dp[n][0] + 1;
                dp[n + s][1] = dp[n][1] + 1;
            }
            else if((dp[n + s][0] == dp[n][0] + 1) && (dp[n + s][1] < dp[n][1] + 1))
            {
                dp[n + s][1] = dp[n][1] + 1;
            }
        }
        
        for(int d = 2;d <= 40;d += 2)
        {
            if(n + d > target) break;
            if(dp[n + d][0] > dp[n][0] + 1)
            {
                dp[n + d][0] = dp[n][0] + 1;
                dp[n + d][1] = dp[n][1];
            }
            else if((dp[n + d][0] == dp[n][0] + 1) && (dp[n + d][1] < dp[n][1]))
            {
                dp[n + d][1] = dp[n][1];
            }
        }
        
        for(int t = 3;t <= 60;t += 3)
        {
            if(n + t > target) break;
            if(dp[n + t][0] > dp[n][0] + 1)
            {
                dp[n + t][0] = dp[n][0] + 1;
                dp[n + t][1] = dp[n][1];
            }
            else if((dp[n + t][0] == dp[n][0] + 1) && (dp[n + t][1] < dp[n][1]))
            {
                dp[n + t][1] = dp[n][1];
            }
        }
        
        if(n + 50 > target) continue;
        if(dp[n + 50][0] > dp[n][0] + 1)
        {
            dp[n + 50][0] = dp[n][0] + 1;
            dp[n + 50][1] = dp[n][1] + 1;
        }
        else if((dp[n + 50][0] == dp[n][0] + 1) && (dp[n + 50][1] < dp[n][1] + 1))
        {
            dp[n + 50][1] = dp[n][1] + 1;
        }
    }
    return dp[target];
}