#include <iostream>
#include <string>
using namespace std;

bool check(string &str, int start, int end)
{
    while(start < end)
        if(str[start++] != str[end--])
            return false;
    return true;    
}

int solution(string s)
{
    int answer = 0;
    for(int i = s.length();i > 1;i--)
    {
        for(int j = 0;j < s.length() - i + 1;j++)
        {
            int start = j, end = j + i - 1;
            if(check(s, start, end))
                return i;
        }
    }
    return 1;
}