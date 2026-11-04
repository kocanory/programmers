#include <string>
#include <vector>

using namespace std;

int Max = -1;
vector<int> answer;

void solve(int n, vector<int> &info, vector<int> points){
    if(points.size() > 11 || n < 0) return;
    if(n == 0){
        while(points.size() < 11) points.push_back(0);
        int r = 0, a = 0;
        for(int i = 0;i < 11;i++){
            if(!info[i] && !points[i]) continue;
            if(points[i] > info[i]) r += 10 - i;
            else a += 10 - i;
        }
        
        if(r <= a) return;
        
        if(r - a >= Max){
            if(r - a > Max){
                Max = r - a;
                answer = points;
            }
            else{
                for(int i = 10;i >= 0;i--){
                    if(!answer[i] && !points[i]) continue;
                    if(points[i] > answer[i])
                        answer = points;
                    break;
                }
            }
        }
        return;
    }
    
    for(int i = 0;i <= n;i++){
        points.push_back(i);
        solve(n - i, info, points);
        points.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    solve(n, info, vector<int>());
    if(answer.empty()) answer.push_back(-1);
    return answer;
}