#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = false;
    stack<char> st;
    for(auto a : s)
    {
        if(a == '(') st.push('(');
        else if(a == ')' && !st.empty()) st.pop();
        else if(a == ')' && st.empty()) return false;
    }
    if(!st.empty()) answer = false;
    else answer = true;
    return answer;
}