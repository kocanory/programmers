#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> wins(n + 1, vector<bool>(n + 1, false));
    vector<vector<bool>> loses(n + 1, vector<bool>(n + 1, false));
    
    for(auto r : results)
    {
        wins[r[0]][r[1]] = true;
        loses[r[1]][r[0]] = true;
    }
    
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= n;k++)
            {
                if(wins[i][k] && wins[k][j])
                {
                    wins[i][j] = true;
                    loses[j][i] = true;
                }
                
                if(loses[i][k] && loses[k][j])
                {
                    wins[j][i] = true;
                    loses[i][j] = true;
                }
                
            }
        }
    }
    
    for(int i = 1;i <= n;i++)
    {
        int count = 0;
        for(int j = 1;j <= n;j++)
        {
            if(loses[i][j] || wins[i][j]) count++;
        }
        if(count == n - 1) answer++;
    }
    
    return answer;
}