#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;
unordered_map<string, vector<int>> um;
void add(vector<string> &s, string str, int count, int score)
{
    if(count >= 4)
    {
        um[str].push_back(score);
        return;
    }
    for(int i = 0;i < 2;i++)
    {
        if(i == 0)
            add(s, str + s[count], count + 1, score);
        else
            add(s, str + "-", count + 1, score);    
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(auto i : info)
    {
        stringstream ss(i);
        string s;
        vector<string> iv;
        while(getline(ss, s, ' '))
            iv.push_back(s);
        add(iv, "", 0, stoi(iv.back()));
    }
    
    for(auto &u : um)
        sort(u.second.begin(), u.second.end());
    
    for(auto q : query)
    {
        vector<string> qv;
        stringstream ss(q);
        string s;
        while(getline(ss, s, ' '))
            if(s != "and")
                qv.push_back(s);
        int score = stoi(qv.back());
        vector<int> sv = um[qv[0] + qv[1] + qv[2] + qv[3]];
        if(!sv.empty())
        {
            int idx = lower_bound(sv.begin(), sv.end(), score) - sv.begin();
            answer.push_back(sv.size() - idx);
        }
        else
            answer.push_back(0);
    }
    
    return answer;
}