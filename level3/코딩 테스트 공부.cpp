#include <string>
#include <vector>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_req = -1, cop_req = -1;
    
    for(auto p : problems)
    {
        if(alp_req < p[0]) alp_req = p[0];
        if(cop_req < p[1]) cop_req = p[1];
    }
    
    if(alp >= alp_req && cop >= cop_req) return 0;
    
    vector<vector<int>> dp(alp_req + 1, vector<int>(cop_req + 1, 1e9));
    
    if(alp > alp_req) alp = alp_req;
    if(cop > cop_req) cop = cop_req;
    
    dp[alp][cop] = 0;
    for(int i = alp;i <= alp_req;i++)
    {
        for(int j = cop;j <= cop_req;j++)
        {
            if(j + 1 <= cop_req) dp[i][j + 1] = min(dp[i][j+1], dp[i][j] + 1);
            if(i + 1 <= alp_req) dp[i + 1][j] = min(dp[i+1][j], dp[i][j] + 1);
            for(auto p : problems)
            {
                if(i >= p[0] && j >= p[1])
                    dp[min(i + p[2], alp_req)][min(j + p[3], cop_req)] = min(dp[min(i + p[2], alp_req)][min(j + p[3], cop_req)], dp[i][j] + p[4]);
            }
        }
    }
    return answer = dp[alp_req][cop_req];
}