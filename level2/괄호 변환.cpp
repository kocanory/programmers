#include <string>
#include <vector>

using namespace std;

string solve(string p){
    string u = "", v = "";
    int flag = true, cnt = 0;
    
    if(p.empty()) return "";
    
    for(auto a : p){
        if(a == '(') cnt++;
        else cnt--;
        
        if(flag) u += a;
        else v += a;
        
        if(!cnt) flag = false;
    }
    
    if(u[0] == '(') return u + solve(v);
    
    u = u.substr(1, u.size() - 2);
    for(int i = 0;i < u.size();i++){
        if(u[i] == '(') u[i] = ')';
        else u[i] = '(';
    }
    
    return '(' + solve(v) + ')' + u;
}

string solution(string p) {
    string answer = solve(p);
    return answer;
}