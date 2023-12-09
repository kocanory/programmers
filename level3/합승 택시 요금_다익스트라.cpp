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
    
    for(int i = 1;i <= n;i++)
        arr[i][i] = 0;
    
    for(int i = 1;i <= n;i++)
    {
        vector<bool> check(n + 1, false);
        check[i] = true;
        for(int j = 1;j <=n ;j++)
        {
            int Minval = 100001 * 200;
            int index;
            for(int j_1 = 1; j_1 <= n;j_1++)
            {
                if(!check[j_1] && (Minval > arr[i][j_1]))
                {
                    index = j_1;
                    Minval = arr[i][j_1];
                }
            }
            check[index] = true;
            
            for(int k = 1;k <= n;k++)
            {
                arr[i][k] = min(arr[i][k], arr[index][k] + Minval);
            }
        }
    }
    
    int answer = 1e9;
    for(int i = 1;i <= n;i++)
        answer = min(answer, arr[s][i]+arr[i][a] + arr[i][b]);
    return answer;
}