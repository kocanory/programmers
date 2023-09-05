#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.length();
    for(int i = 0;i<size;i++)
    {
        vector<char> temp;
        for(auto a : s)
        {
            if(a == '(' || a == '[' || a == '{')
                temp.push_back(a);
            
            if(temp.empty() && (a == ')' || a == ']' || a == '}'))
            {
                temp.push_back(a);
                break;
            }
            
            if(a == ')' && temp.back() == '(')
                temp.pop_back();
            else if(a == ')' && temp.back() != '(')
            {
                break;
            }
            
            if(a == ']' && temp.back() == '[')
                temp.pop_back();
            else if(a == ']' && temp.back() != '[')
            {
                break;
            }
            
            if(a == '}' && temp.back() == '{')
                temp.pop_back();
            else if(a == '}' && temp.back() == '{')
            {
                break;
            }
        }
        
        if(temp.empty()) answer++;
        
        s += s[0];
        s.erase(0, 1);
    }
    return answer;
}