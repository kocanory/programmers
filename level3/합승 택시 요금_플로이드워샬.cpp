#include <string>
#include <vector>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    vector<vector<int>> arr(n + 1, vector<int> (n + 1, 100001 * 200));
    
    for(auto f : fares)
    {
        arr[f[0]][f[1]] = f[2];
        arr[f[1]][f[0]] = f[2];
    }
    
    for(int k = 1;k <= n;k++)
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
    for(int i = 1;i <= n;i++)
        arr[i][i] = 0;
    
    int answer = 1e9;
    for(int i = 1;i <= n;i++)
        answer = min(answer, arr[s][i]+arr[i][a] + arr[i][b]);
    return answer;
}