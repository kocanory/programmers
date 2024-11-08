#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> board[105][105];

void find(vector<vector<int>> points, vector<int> route){
    int x = points[route[0] - 1][0];
    int y = points[route[0] - 1][1];
    int time = 1;
    board[x][y].push_back(1);
    
    for(int i = 1;i < route.size();i++){
        int nx = points[route[i] - 1][0];
        int ny = points[route[i] - 1][1];
        
        while(x != nx){
            if(x < nx) x++;
            if(x > nx) x--;
            time++;
            board[x][y].push_back(time);
        }
        
        while(y != ny){
            if(y < ny) y++;
            if(y > ny) y--;
            time++;
            board[x][y].push_back(time);
        }
    }
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    for(auto &r : routes) find(points, r);
    for(int i = 1;i <=100;i++){
        for(int j = 1;j <= 100;j++){
            if(!board[i][j].empty()){
                sort(board[i][j].begin(), board[i][j].end());
                board[i][j].push_back(-1);
                int pre = board[i][j][0];
                int cnt = 0;
                for(int k = 1;k < board[i][j].size();k++){
                    int cur = board[i][j][k];
                    if(pre == cur) cnt++;
                    else{
                        if(cnt > 0) answer++;
                        cnt = 0;
                        pre = cur;
                    }
                }
            }
        }
    }
    return answer;
}