#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0;i < timelogs.size();i++){
        bool flag = true;
        for(int j = 0;j < 7;j++){
            int now = (j + startday - 1) % 7 + 1;
            if(now == 6 || now == 7) continue;
            
            int t = timelogs[i][j] / 100 * 60 + timelogs[i][j] % 100;
            int s = schedules[i] / 100 * 60 + schedules[i] % 100;
            if(t > s + 10){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}