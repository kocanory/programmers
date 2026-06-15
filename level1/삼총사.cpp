#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int cnt, int val, int idx, vector<int> &number){
    if(cnt == 3){
        if(val == 0) answer++;
        return;
    }
    
    for(int i = idx;i < number.size();i++)
        dfs(cnt + 1, val + number[i], i + 1, number);
}

int solution(vector<int> number) {
    dfs(0, 0, 0, number);
    return answer;
}