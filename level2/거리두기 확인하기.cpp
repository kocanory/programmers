#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto p : places){
        vector<pair<int, int>> arr;
        
        for(int i = 0;i < p.size();i++)
            for(int j = 0;j < p[0].size();j++)
                if(p[i][j] == 'P')
                    arr.push_back({i, j});
        
        bool flag = true;
        for(int i = 0;i < arr.size() && flag;i++){
            for(int j = i + 1;j < arr.size() && flag;j++){
                auto [x1, y1] = arr[i];
                auto [x2, y2] = arr[j]; 
                int dist = abs(x1 - x2) + abs(y1 - y2);
                
                if(dist <= 2){
                    if(dist == 2){
                        if(x1 == x2){
                            if(p[x1][y1 + 1] == 'X')
                                continue;
                        }
                        else if(y1 == y2){
                            if(p[x1 + 1][y1] == 'X')
                                continue;
                        }
                        else{
                            if(p[x1][y2] == 'X' && p[x2][y1] == 'X')
                                continue;
                        }
                    }
                    flag = false;
                }
            }
        }
        answer.push_back(flag);
    }
    
    return answer;
}