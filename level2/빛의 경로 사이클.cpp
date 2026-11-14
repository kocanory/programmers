#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n = grid.size(), m = grid[0].size(), size = n * m;
    vector<bool> visited(size * 4);
    
    for(int i = 0;i < size * 4;i++){
        int now = i, x = now / 4 / m, y = now / 4 % m, idx = now % 4;
        
        if(visited[i]) continue;
        visited[i] = true;
        int cnt = 0;
        
        while(true){
            auto [dx, dy] = d[idx];
            x = (x + dx + n) % n, y = (y + dy + m) % m;
            cnt++;
            if(grid[x][y] == 'L') idx = (idx + 3) % 4;
            else if(grid[x][y] == 'R') idx = (idx + 1) % 4;
            
            now = (x * m + y) * 4 + idx;
            if(now == i){
                answer.push_back(cnt);
                break;
            }
            
            if(visited[now]) break;
            visited[now] = true;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}