#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int answer = (int)1e9;
    vector<vector<int>> dp(info.size() + 1, vector<int>(m, 1e9));
    dp[0][0] = 0;
    
    for(int i = 1;i <= info.size();i++){
        int a = info[i - 1][0], b = info[i - 1][1];
        for(int j = 0;j < m;j++){
            dp[i][j] = min(dp[i][j], dp[i - 1][j]+ a);
            if(j + b < m)
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
        }
    }
    
    for(int i = 0;i < m;i++)
        answer = min(answer, dp[info.size()][i]);
    
    return answer >= n ? -1 : answer;
}