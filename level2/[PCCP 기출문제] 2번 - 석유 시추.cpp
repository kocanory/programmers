#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<vector<bool>> check;
vector<int> arr;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int sx, int sy, vector<vector<int>> &land){
    queue<pair<int, int>> q;
    set<int> pos;
    q.push({sx, sy});
    check[sx][sy] = true;
    int cnt = 0, n = land.size(), m = land[0].size();
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        pos.insert(y);
        
        for(auto [dx, dy] : d){
            int nx = x + dx, ny = y + dy;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] && !check[nx][ny]){
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    
    for(auto y : pos)
        arr[y] += cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0, n = land.size(), m = land[0].size();
    arr.assign(m, 0);
    check.assign(n, vector<bool>(m));
    
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            if(land[i][j] && !check[i][j])
                bfs(i, j, land);
    
    for(auto a : arr)
        answer = max(answer, a);
    
    return answer;
}