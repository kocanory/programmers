#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<string> &maps, pair<int, int> s, pair<int, int> e){
    int n = maps.size(), m = maps[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> check(n, vector<int>(m, -1));
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    q.push(s);
    check[s.first][s.second] = 0;
    
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        
        if(e == make_pair(x, y)) break;
        
        for(auto [dx, dy] : d){
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] == 'X' || check[nx][ny] != -1) continue;
            q.push({nx, ny});
            check[nx][ny] = check[x][y] + 1;
        }
    }
    return check[e.first][e.second];
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> s, l, e;
    
    for(int i = 0;i < maps.size();i++){
        for(int j = 0;j < maps[i].size();j++){
            if(maps[i][j] == 'S')
                s = {i, j};
            else if(maps[i][j] == 'L')
                l = {i, j};
            else if(maps[i][j] == 'E')
                e = {i, j};
        }
    }
    
    int r1 = bfs(maps, s, l), r2 = bfs(maps, l, e);
    
    if(r1 != -1 && r2 != -1) answer = r1 + r2;
    else answer = -1;
    
    return answer;
}