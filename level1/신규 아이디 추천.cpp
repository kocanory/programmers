#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "", tmp = "";
    
    for(char &n : new_id)
        n = tolower(n);
        
    for(auto n : new_id)
        if(islower(n) || isdigit(n) || n == '-' || n == '_' || n == '.')
            tmp += n;
            
    if(!tmp.empty()){
        answer = tmp[0];
        for(int i = 1;i < tmp.size();i++){
            if (tmp[i - 1] == tmp[i] && tmp[i] == '.') continue;
            answer += tmp[i];
        }
    }
    
    if(!answer.empty() && answer[0] == '.') answer.erase(answer.begin());
    if(!answer.empty() && answer[answer.size() - 1] == '.') answer.erase(answer.end() - 1);
    if(answer.empty()) answer += 'a';
    if(answer.size() >= 16) {
        answer = answer.substr(0, 15);
        if(answer[answer.size() - 1] == '.')
            answer.erase(answer.end() - 1);
    }
    if(answer.size() <= 2){
        char back = answer[answer.size() - 1];
        while(answer.size() < 3)
            answer += back;
    }
    
    
    return answer;
}