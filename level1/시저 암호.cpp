#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(auto a : s){
        if(isalpha(a))
            a = (a - (islower(a) ? 'a' : 'A') + n) % 26 + (islower(a) ? 'a' : 'A');
        answer += a;
    }
    
    return answer;
}