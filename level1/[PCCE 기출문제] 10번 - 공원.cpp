#include <string>
#include <vector>

using namespace std;

bool check(int x, int y, int m, vector<vector<string>> &park){
    if(x + m - 1 >= park.size() || y + m - 1 >= park[0].size()) return false;
    for(int i = x;i < x + m;i++)
        for(int j = y;j < y + m;j++)
            if(park[i][j] != "-1")
                return false;
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    for(int i = 0;i < park.size();i++){
        for(int j = 0;j < park[0].size();j++){
            if(park[i][j] == "-1"){
                for(auto &m : mats){
                    if(check(i, j, m, park))
                        answer = max(answer, m);
                }
            }
        }
    }
    return answer == 0 ? -1 : answer;
}