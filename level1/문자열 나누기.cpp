#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0, same = 0, diff = 0, idx = 0;
    
    for(int i = 0;i < s.size();i++){
        if(s[i] == s[idx]) same++;
        else diff++;
        
        if(same == diff){
            answer++;
            same = 0, diff = 0, idx = i + 1;
        }
    }
    
    if(same || diff) answer++;
    
    return answer;
}