#include <iostream>
#include <vector>
using namespace std;

int dp[51][51];
bool visit[51];
bool visited[51];
int count = 0;

void dfs(int now, int limit, int num, int sum)
{
    for(int i = 1;i<= num;i++)
    {
        if(!visited[i] && sum + dp[now][i] <= limit)
        {
            visited[i] = true;
            visit[i] = true;
            dfs(i, limit, num, sum + dp[now][i]);
            visited[i] = false;
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i = 1;i<=50;i++)
    {
        for(int j = 1;j<=50;j++)
            dp[i][j] = 1e9;
    }
    for(auto r : road)
    {
        dp[r[0]][r[1]] = min(dp[r[0]][r[1]], r[2]);
        dp[r[1]][r[0]] = min(dp[r[1]][r[0]], r[2]);
    }
    
    visited[1] = true;
    visit[1] = true;
    dfs(1, K, N, 0);
    for(int i = 1;i<=N;i++)
        if(visit[i]) count++;
    return answer = count;
}