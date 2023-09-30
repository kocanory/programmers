#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string convert(string time)
{
    stringstream ss(time);
    string s;
    vector<string> t;
    while(getline(ss, s, ':'))
        t.push_back(s);
    return to_string(stoi(t[0]) * 60 + stoi(t[1]));
}

bool comp(vector<string> a, vector<string> b)
{
    return stoi(a[1]) < stoi(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<vector<string>> s;
    for(int i = 0;i<plans.size();i++)
        plans[i][1] = convert(plans[i][1]);
    sort(plans.begin(), plans.end(), comp);
    vector<string> now;
    while(true)
    {
        if(plans.size() > 1)
        {
            now = plans[0];
            plans.erase(plans.begin());
            if(stoi(now[1]) + stoi(now[2]) <= stoi(plans[0][1]))
            {
                answer.push_back(now[0]);
                int time = stoi(now[1]) + stoi(now[2]);
                int interval = stoi(plans[0][1]) - time;
                while(!s.empty())
                {
                    if(stoi(s.back()[2]) <= interval)
                    {
                        interval -= stoi(s.back()[2]);
                        answer.push_back(s.back()[0]);
                        s.pop_back();
                    }
                    else
                    {
                        s.back()[2] = to_string(stoi(s.back()[2]) - interval);
                        break;
                    }
                }
            }
            else
            {
                now[2] = to_string(stoi(now[2]) - (stoi(plans[0][1]) - stoi(now[1])));
                s.push_back(now);
            }
        }
        else
        {
            answer.push_back(plans.back()[0]);
            while(!s.empty())
            {
                answer.push_back(s.back()[0]);
                s.pop_back();
            }
            break;
        }
    }
    return answer;
}