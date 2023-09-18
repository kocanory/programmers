#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> st;
    for(auto a : s)
    {
        if(!st.empty() && st.top() == a) st.pop();
        else st.push(a);
    }
    return answer = st.empty() ? 1 : 0;
}