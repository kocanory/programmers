#include <string>
#include <vector>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int> (m + 1, 0));
    for(auto p : puddles)
        arr[p[1]][p[0]] = 1;
    arr[0][1] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)a
        {
            if(arr[i][j])
                arr[i][j] = 0;
            else
                arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000007;
        }
    }
    return answer = arr[n][m];
}