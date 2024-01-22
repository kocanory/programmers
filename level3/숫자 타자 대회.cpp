#include <string>
#include <vector>

using namespace std;

vector<vector<int>> weight = {
        { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
        { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
        { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
        { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
        { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
        { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
        { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
        { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
        { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
        { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
    };

vector<vector<vector<int>>> dp; 
string num;
int len;

int solve(int index, int L, int R)
{
    if(index == len) return 0;
    if(dp[index][L][R] != -1) return dp[index][L][R];
    
    int n = num[index] - '0';
    int val = 1e9;
    
    if(n != R) val = min(solve(index + 1, n, R) + weight[L][n], val);
    if(n != L) val = min(solve(index + 1, L, n) + weight[R][n], val);
    
    return dp[index][L][R] = val;
}

int solution(string numbers) {
    num = numbers;
    len = numbers.length();
    for(int i = 0;i<= len;i++)
    {
        vector<vector<int>> arr(10, vector<int>(10, -1));
        dp.push_back(arr);
    }
    return solve(0, 4, 6);
}