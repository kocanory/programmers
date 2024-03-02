#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int MOD = 1000000007;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

vector<vector<long long>> mulmat(vector<vector<long long>> &a, vector<vector<long long>> &b){
    int n = a.size();
    vector<vector<long long>> arr(n, vector<long long>(n));
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                arr[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
            }
        }
    }
    return arr;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    int n = grid.size();
    int m = grid[0].size();
    int dl = d.size();
    
    vector<vector<vector<long long>>> dp(dl + 1, vector<vector<long long>> (n * m, vector<long long>(n * m)));
    
    for(int i = 0;i < n * m;i++) dp[0][i][i] = 1;
    
    for(int l = 1;l <= dl;l++){
        for(int i = 0;i < n * m;i++){
            int x = i / m;
            int y = i % m;
            
            for(int dir = 0;dir < 4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] - grid[x][y] != d[l - 1]) continue;
                
                for(int j = 0;j < n * m;j++){
                    dp[l][j][nx * m + ny] += dp[l - 1][j][i] % MOD; 
                    dp[l][j][nx * m + ny] %= MOD;
                    
                }
            }
        }
    }
    
    int count = 0;
    while(pow(2, count) < k) count++;    
    
    vector<vector<vector<long long>>> edge(count + 1, vector<vector<long long>>(n * m, vector<long long>(n * m)));
    
    edge[0] = dp[dl];
    for(int c = 1;c <= count;c++){
        edge[c] = mulmat(edge[c-1], edge[c-1]);
    }
    
    vector<vector<long long>> mat(n * m, vector<long long>(n * m));
    for(int i = 0;i < n * m;i++){
        mat[i][i] = 1;
    }
    
    int kNum = k;
    while(kNum > 0){
        if(kNum >= pow(2, count)){
            mat = mulmat(mat, edge[count]);
            kNum -= pow(2, count);
        }
        count--;
    }
    
    long long answer = 0;
    for(int i = 0;i < n * m;i++){
        for(int j =0;j < n * m;j++){
            answer += mat[i][j];
            answer %= MOD;
        }
    }
    return (int)answer;
}