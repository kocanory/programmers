#include <map>
#include <vector>
#include <string>

using namespace std;

bool check[11][11][4];
map<char, int> idx = {{'U', 0}, {'D', 3}, {'L', 1}, {'R', 2}};
vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int solution(string dirs) {
    int answer = 0, x = 5, y = 5;
    
    for(auto d : dirs){
        int nx = x + dir[idx[d]].first, ny = y + dir[idx[d]].second;
        
        if(nx >= 0 && nx <= 10 && ny >= 0 && ny <= 10){
            if(!check[nx][ny][idx[d]] && !check[x][y][3 - idx[d]]){
                answer++;
                check[nx][ny][idx[d]] = true;
                check[x][y][3 - idx[d]] = true;
            }
            x = nx, y = ny;
        }
    }
    
    return answer;
}