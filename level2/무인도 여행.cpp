#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> arr, check;
vector<int> answer;
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = true;
    int res = 0;
    
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        res += arr[x][y];
        
        for(auto [dx, dy] : d){
            int nx = x + dx, ny = y + dy;
            
            if(nx >= 0 && nx < arr.size() && ny >= 0 && ny < arr[0].size() && arr[nx][ny] != -1 && !check[nx][ny]){
                q.push({nx, ny});
                check[nx][ny] = true;
            }
        }
    }
    
    return res;
}

vector<int> solution(vector<string> maps) {
    arr.assign(maps.size(), vector<int>(maps[0].size()));
    check = arr;
    
    for(int i = 0;i < maps.size();i++)
        for(int j = 0;j < maps[0].size();j++){
            if(isdigit(maps[i][j]))
                arr[i][j] = maps[i][j] - '0';
            else
                arr[i][j] = -1;
        }
    
    for(int i = 0;i < maps.size();i++)
        for(int j = 0;j < maps[0].size();j++){
            if(arr[i][j] != -1 && !check[i][j])
                answer.push_back(bfs(i, j));
        }
    
    (answer.empty() ? answer.push_back(-1) : sort(answer.begin(), answer.end()));
    return answer;
}