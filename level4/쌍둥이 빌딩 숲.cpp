#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr;

int MOD = 1000000007;

int dfs(int n, int c){
    if(n == 0) return c == 0 ? 1 : 0;
    if(n < c || c < 0) return 0;
    if(arr[n][c] != 0) return arr[n][c];
    long result = 0;
    result += (long)dfs(n - 1, c - 1);
    result += ((long)dfs(n - 1, c) * (n - 1) * 2);
    return arr[n][c] = (int)(result % MOD);
}

int solution(int n, int count) {
    arr.resize(n + 1, vector<int>(count + 1, 0));
    return dfs(n, count);
}