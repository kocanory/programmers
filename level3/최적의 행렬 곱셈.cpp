#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int size = matrix_sizes.size();
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 1e9));
    vector<int> d(size + 1);
    d[0] = matrix_sizes.front()[0];
    for(int i = 0;i < size;i++)
        d[i + 1] = matrix_sizes[i][1];
    
    for(int n = 0;n < size;n++)
    {
        for(int i = 1;i <= size - n;i++)
        {
            int j = i + n;
            if(i == j) dp[i][j] = 0;
            else
            {
                for(int k = i;k <= j - 1;k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + d[i - 1] * d[k] * d[j]);
                }
            }
            
        }
    }
    return answer = dp[1][size];
}