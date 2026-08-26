#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<tuple<int, int, int>> q;
vector<vector<bool>> check;

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int n = maps.size(), m = maps[0].size();
    check.assign(n, vector(m, false));
    
    q.push({0, 0, 1});
    check[0][0] = true;
    
    while(!q.empty()){
        auto [x, y, cnt] = q.front();
        q.pop();
        
        if(x == n - 1 && y == m - 1)
            return cnt;
        
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny] || !maps[nx][ny]) continue;
            
            q.push({nx, ny, cnt + 1});
            check[nx][ny] = true;
        }
    }
    return answer;
}