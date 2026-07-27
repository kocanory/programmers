#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, pair<int, int>> dir = {{'E', {0, 1}}, {'S', {1, 0}}, {'W', {0, -1}}, {'N', {-1, 0}}};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x = -1, y = -1;
    
    for(int i = 0;i < park.size();i++){
        for(int j = 0;j < park[0].size();j++)
            if(park[i][j] == 'S'){
                x = i, y = j;
                break;
            }
        if(x != -1)
            break;
    }
    
    for(auto r : routes){
        char op = r[0];
        int n = r[2] - '0', nx = x, ny = y;
        bool flag = true;
        
        while(n){
            nx += dir[op].first;
            ny += dir[op].second;
            
            if(nx < 0 || nx >= park.size() || ny < 0 || ny >= park[0].size() || park[nx][ny] == 'X'){
                flag = false;
                break;
            }
            n--;
        }
        
        if(flag){
            x = nx, y = ny;
        }
    }
    
    answer = {x, y};
    return answer;
}