#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(int sx, int sy, int ex, int ey, vector<string> &board){
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> check(n, vector<bool>(m));
    queue<tuple<int, int, int>> q;
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    check[sx][sy] = true;
    q.push({0, sx, sy});
    
    while(!q.empty()){
        auto [cnt, x, y] = q.front();
        q.pop();
        
        if(x == ex && y == ey) return cnt;
        
        for(auto [dx, dy] : d){
            int nx = x, ny = y;
            
            while(nx + dx >= 0 && nx + dx < n && ny + dy >= 0 && ny + dy < m && board[nx + dx][ny + dy] != 'D'){
                nx += dx;
                ny += dy;
            }
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !check[nx][ny]){
                check[nx][ny] = true;
                q.push({cnt + 1, nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<string> board) {
    int sx, sy, ex, ey;
    
    for(int i = 0;i < board.size();i++)
        for(int j = 0;j < board[0].size();j++){
            if(board[i][j] == 'R')
                sx = i, sy = j;
            else if(board[i][j] == 'G')
                ex = i, ey = j;
        }
    
    return bfs(sx, sy, ex, ey, board);
}