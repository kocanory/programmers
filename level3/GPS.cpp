#include <vector>
#include <map>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    map<int, vector<int>> neighbor;
    vector<vector<int>> dp(k, vector<int>(n + 1, 1e9));
    for(auto e : edge_list)
    {
        neighbor[e[0]].push_back(e[1]);
        neighbor[e[1]].push_back(e[0]);
    }
    int start = gps_log.front(), end = gps_log.back();
    dp[0][start] = 0;
    
    for(int i = 0;i < k - 1;i++)
    {
        for(int j = 1;j < n + 1;j++)
        {
            if(dp[i][j] == 1e9) continue;
            
            vector<int> nextCandidate = neighbor[j];
            nextCandidate.push_back(j);
            
            for(auto next : nextCandidate)
            {
                int val = dp[i][j];
                if(next != gps_log[i + 1]) val++;
                dp[i + 1][next] = min(dp[i + 1][next], val);
            }
        }
    }
    return answer = (dp[k - 1][end] != 1e9) ? dp[k-1][end] : -1;
}