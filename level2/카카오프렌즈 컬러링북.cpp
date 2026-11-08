#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> check;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(int sx, int sy, int m, int n, vector<vector<int>> &picture){
    
    int cnt = 0;
    queue<pair<int, int>> q;
    check[sx][sy] = true;
    q.push({sx, sy});
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        
        for(auto [dx, dy] : d){
            int nx = x + dx, ny = y + dy;
            
            if(nx < 0 || nx >= m || ny < 0 || ny > n || check[nx][ny] || picture[nx][ny] != picture[sx][sy]) continue;
            
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    check.assign(m, vector<bool>(n));
    
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(picture[i][j] != 0 && !check[i][j]){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, m, n, picture));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}