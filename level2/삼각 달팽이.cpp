#include <string>
#include <vector>

using namespace std;

int cnt = 1;
vector<vector<int>> check;

void solve(int x, int y, int sz){
    if(sz <= 0) return;
    if(sz == 1){
        check[x][y] = cnt;
        return;
    }
    
    for(int i = 0;i < sz;i++) check[x + i][y] = cnt++;
    for(int i = 1;i < sz;i++) check[x + sz - 1][y + i] = cnt++;
    for(int i = 1;i < sz - 1;i++) check[x + sz - 1 - i][y + sz - 1 - i] = cnt++;
    solve(x + 2, y + 1, sz - 3);
}

vector<int> solution(int n) {
    vector<int> answer;
    check.assign(n, vector<int>(n));
    solve(0, 0, n);
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= i;j++)
            answer.push_back(check[i][j]);
    return answer;
}