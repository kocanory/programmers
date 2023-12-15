#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for(auto m : money)
    {
        for(int i = m;i <= n;i++)
            dp[i] += dp[i - m];
    }
    return answer = dp[n];
}