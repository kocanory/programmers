#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<vector<long long>>> dp(m + 1, vector<vector<long long>>(n + 1, vector<long long>(2)));
    
    for(int x = 0;x < m; x++)
    {
        if(city_map[x][0] == 1) break;
        dp[x][0][1] = 1;
    }
    
    for(int y = 0;y < n; y++)
    {
        if(city_map[0][y] == 1) break;
        dp[0][y][0] = 1;
    }
    
    for(int x = 1;x < m;x++)
    {
        for(int y = 1;y < n;y++)
        {
            if(city_map[x - 1][y] == 0)
            {
                dp[x][y][1] += ((dp[x - 1][y][0] + dp[x - 1][y][1]) % MOD);
            }
            if(city_map[x][y - 1] == 0)
            {
                dp[x][y][0] += ((dp[x][y - 1][0] + dp[x][y - 1][1]) % MOD);
            }
            if(city_map[x - 1][y] == 2)
            {
                dp[x][y][1] += (dp[x - 1][y][1] % MOD);
            }
            if(city_map[x][y - 1] == 2)
            {
                dp[x][y][0] += (dp[x][y - 1][0] % MOD);
            }
        }
    }
    return answer = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
}