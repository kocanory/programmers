#include <string>
#include <vector>

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    
    if(t1 <= temperature && temperature <= t2) return 0;
    
    temperature -= -10;
    t1 -= -10;
    t2 -= -10;
    
    vector<vector<int>> dp(1005, vector<int>(55, 1e9));
    dp[0][temperature] = 0;
    for(int i = 0;i < onboard.size() - 1;i++)
    {
        for(int j = 0;j <= 50;j++)
        {
            if(onboard[i] && (j < t1 || j > t2)) continue;
            int nextTemperature = j;
            if(j < temperature && j < 50) nextTemperature++;
            else if(j > temperature && j > 0) nextTemperature--;
            dp[i + 1][nextTemperature] = min(dp[i][j], dp[i + 1][nextTemperature]);
            
            if(j > 0) dp[i + 1][j - 1] = min(dp[i][j] + a, dp[i + 1][j - 1]);
            if(j < 50) dp[i + 1][j + 1] = min(dp[i][j] + a, dp[i + 1][j + 1]);
            
            dp[i + 1][j] = min(dp[i][j] + b, dp[i + 1][j]);
        }
    }
    int answer = 1e9;
    for(int j = 0;j < 50;j ++)
    {
        if(onboard.back() && (j < t1 || j > t2)) continue;
        answer = min(dp[onboard.size() - 1][j], answer);
    }
    return answer;
}