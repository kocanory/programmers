#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    char start = ' ';
    
    for(auto a : s){
        if(a == ' ') start = a;
        else if(start == ' '){
            a = toupper(a);
            start = a;
        }
        else
            a = tolower(a);
        
        answer += a;
    }
    
    return answer;
}