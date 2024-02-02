#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> dp(n + 5, 0);
    vector<long long> cache(3, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    for(int i = 4; i <= n;i++)
    {
        dp[i] += dp[i - 1] + (2 * dp[i - 2]) + (5 * dp[i - 3]);
        cache[(i - 4) % 3] = (cache[(i - 4) % 3] + dp[i - 4]) % 1000000007;
        dp[i] += (cache[0] + cache[1] + cache[2] + cache[i % 3]) * 2;
        dp[i] %= 1000000007;
    }
    return dp[n];
}