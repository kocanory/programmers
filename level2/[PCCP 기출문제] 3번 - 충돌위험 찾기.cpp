#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> check[101][101];

void find(vector<vector<int>> &points, vector<int> route){
    int t = 0, x = points[route[0] - 1][0], y = points[route[0] - 1][1];
    check[x][y][t]++;
    
    for(int i = 1;i < route.size();i++){
        int nx = points[route[i] - 1][0], ny = points[route[i] - 1][1];
        while(x != nx){
            if(x < nx) x++;
            else x--;
            t++;
            check[x][y][t]++;
        }
        
        while(y != ny){
            if(y < ny) y++;
            else y--;
            t++;
            check[x][y][t]++;
        }
    }
    
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    for(auto r : routes) find(points, r);
    
    for(int i = 1;i <= 100;i++){
        for(int j = 1;j <= 100;j++){
            if(!check[i][j].empty()){
                for(auto [k, v] : check[i][j]){
                    if(v > 1)
                        answer++;
                }
            }
        }
    }
    return answer;
}