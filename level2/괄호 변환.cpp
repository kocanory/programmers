#include <string>
#include <vector>

using namespace std;
string returnU(string p)
{
    if(p.empty()) return "";
    string u = "";
    string v = "";
    bool isU = true;
    int isP = 0;
    for(auto a : p)
    {
        if(a == ')') isP--;
        else isP++;
        if(isU) u += a;
        else v += a;
        if(isP == 0) isU = false;
    }
    if(u[0] == '(') return u + returnU(v);
    
    string ru = "";
    for(int i = 1;i<u.length() - 1;i++)
    {
        if(u[i] == ')') ru += '(';
        else ru += ')';
    }
    return "(" + returnU(v) + ")" + ru;
}
string solution(string p) {
    string answer = "";
    answer = returnU(p);
    return answer;
}