#include <string>
#include <vector>
#include <cmath>

using namespace std;
string character;
int answer;
bool correct(char o, int n1, int n2)
{
    if(o == '=' && n1 == n2) return true;
    else if(o == '>' && n1 > n2) return true;
    else if(o == '<' && n1 < n2) return true;
    else return false;
}

void recursive(string s, vector<string> &data)
{
    if(s.length() < 8)
    {
        for(auto c : character)
        {
            if(s.find(c) == string::npos) recursive(s + c, data);
        }
    }
    else
    {
        for(auto d : data)
        {
            int n1 = abs((int)s.find(d[0]) - (int)s.find(d[2])) - 1;
            int n2 = d[4] - '0';
            char o = d[3];
            if(!correct(o, n1, n2)) return;
        }
        answer++;
    }
}
    
int solution(int n, vector<string> data) {
    answer = 0;
    character = "ACFJMNRT";
    recursive("", data);
    return answer;
}