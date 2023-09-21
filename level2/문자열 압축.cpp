#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000000;
    for(int i = 1;i<=s.length();i++)
    {
        string now = s.substr(0, i);
        int j, count = 1;
        vector<pair<string, int>> arr;
        for(j = i;j<s.length();j+=i)
        {
            string temp;
            if(s.length() - j < i)
                temp = s.substr(j, s.length() - j);
            else
                temp = s.substr(j, i);
            
            if(now != temp)
            {
                arr.push_back({now, count});
                now = temp;
                count = 1;
            }
            else
                count++;
        }
        arr.push_back({now, count});
        int len = 0;
        for(auto a : arr)
        {
            if(a.second == 1)
                len += a.first.length();
            else
                len += a.first.length() + to_string(a.second).length();
        }
        if(answer > len) answer = len;
    }    
    return answer;
}