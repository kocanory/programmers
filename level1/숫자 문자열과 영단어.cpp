#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int solution(string s) {
    int answer = 0;
    
    string num = "";
    for(auto a : s){
        if(m.find(num) != m.end()){
            answer = answer * 10 + m[num];
            num = "";
        }
        if(isdigit(a)) {
            answer = answer * 10 + (a - '0');
            num = "";
        }
        else num += a;
    }
    
    if(num.size())
        answer = answer * 10 + m[num];
    
    return answer;
}