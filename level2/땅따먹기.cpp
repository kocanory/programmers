#include <iostream>
#include <vector>
using namespace std;

int dp[100000][4] = {0, };
int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for(int i = 0;i<land.size();i++)
    {
        for(int j = 0; j < 4;j++)
        {
            if(i == 0)
                dp[i][j] = land[i][j];
            else
            {
                int max = 0;
                for(int k = 0;k<4;k++)
                {
                    if(j != k && dp[i - 1][k] > max)
                        max = dp[i - 1][k];
                }
                dp[i][j] = land[i][j] + max;
            }
        }
    }
    for(int i = 0;i < 4;i++)
    {
        if(answer < dp[land.size() - 1][i])
            answer = dp[land.size() - 1][i];
    }
    return answer;
}