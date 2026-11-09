#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n % 2) return 0;
    vector<long long> dp(n + 1);
    dp[2] = 3;
    
    long long s = 3;
    
    for(int i = 4;i <= n;i += 2){
        dp[i] = (3 * dp[i - 2] + (i >= 6 ? 2 * s : 0) + 2) % 1000000007;
        s += (i >= 6 ? dp[i - 2] : 0);
    }
    return dp[n];
}