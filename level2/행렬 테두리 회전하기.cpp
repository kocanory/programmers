#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr;
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    for(int i = 0;i < rows;i++){
        vector<int> tmp;
        for(int j = 0;j < columns;j++)
            tmp.push_back(i * columns + j + 1);
        arr.push_back(tmp);
    }
    
    for(auto qu : queries){
        int sx = qu[0], sy = qu[1], ex = qu[2], ey = qu[3], back = arr[sx - 1][sy - 1], val = rows * columns, idx = 0;
        
        queue<pair<int, int>> q;
        q.push({sx - 1, sy});
        
        while(true){
            auto [x, y] = q.front();
            q.pop();
            int tmp = back;
            back = arr[x][y];
            arr[x][y] = tmp;
            val = min(val, arr[x][y]);
            
            if(x == sx - 1 && y == sy - 1)
                break;
            
            int nx = x + d[idx].first, ny = y + d[idx].second;
            
            if(nx < sx - 1 || nx >= ex || ny < sy - 1 || ny >= ey) idx++;
            
            nx = x + d[idx].first, ny = y + d[idx].second;
            q.push({nx, ny});
        }
        answer.push_back(val);
    }
    return answer;
}