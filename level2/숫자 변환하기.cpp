#include <string>
#include <vector>

using namespace std;

vector<int> check(1000001);
int Max = (int)1e9;

int dfs(int x, int y, int n){
    if(x == y) return 0;
    if(check[x]) return check[x];
    
    int plus = Max, two = Max, three = Max;
    if(x + n <= y) plus = dfs(x + n, y, n);
    if(x * 2 <= y) two = dfs(x * 2, y, n);
    if(x * 3 <= y) three = dfs(x * 3, y,  n);
    
    int res = min(plus, min(two, three));
    if(res == Max) check[x] = Max;
    else check[x] = res + 1;
    return check[x];
}

int solution(int x, int y, int n) {
    int answer = dfs(x, y, n);
    return (answer == Max ? -1 : answer);
}