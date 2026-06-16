#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int idx = 0;
    
    for(auto a : s){
        if(a == ' ') {
            idx = 0;
            answer += ' ';
        }
        else{
            if(idx % 2) answer += tolower(a);
            else answer += toupper(a);
            idx++;
        }
    }
    
    return answer;
}