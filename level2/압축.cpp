#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b)
{
    if(a.first.length() == b.first.length()) return a.first < b.first;
    return a.first.length() > b.first.length();
}

vector<int> solution(string msg) {
    vector<int> answer;
    vector<pair<string, int>> dict;
    for(int i = 0;i<26;i++)
    {
        string temp = "";
        temp += ('A' + i);
        dict.push_back({temp, i + 1});
    }
    
    while(!msg.empty())
    {
        for(auto a : dict)
        {
            if(msg.find(a.first) == 0)
            {
                answer.push_back(a.second);
                msg.erase(0, a.first.length());
                if(msg.length() > 0)
                {
                    string temp = "";
                    temp += msg[0];
                    string word = a.first + temp;
                    dict.push_back({word, dict.size() + 1});
                    sort(dict.begin(), dict.end(), comp);
                }
                break;
            }
         }
    }
    return answer;
}