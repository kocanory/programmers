#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, n = name.size(), turn = n;
    
    for(int i = 0, idx;i < n;i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
        
        idx = i + 1;
        while(idx < n && name[idx] == 'A') idx++;
        turn = min(turn, i + (n - idx) + min(i, n - idx));
    }
    answer += turn;
    return answer;
}