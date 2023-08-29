#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b)
{
    return a.first < b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<vector<string>> rec;
    map<string, int> m;
    for(auto a : records)
    {
        if(a[11] == 'I')
        {
            vector<string> temp;
            stringstream ss(a);
            string s = "";
            while(getline(ss, s, ' '))
                temp.push_back(s);
            rec.push_back(temp);
        }
        else
        {
            vector<string> temp;
            vector<string> load;
            stringstream ss(a);
            string s = "";
            while(getline(ss, s, ' '))
                temp.push_back(s);
            for(int i = 0;i<rec.size();i++)
                if(rec[i][1] == temp[1])
                {
                    load = rec[i];
                    rec.erase(rec.begin() + i);
                    break;
                }
            vector<int> time1;
            vector<int> time2;
            
            stringstream t1(temp[0]);
            stringstream t2(load[0]);
            
            string t = "";
            while(getline(t1, t, ':'))
                time1.push_back(stoi(t));
            while(getline(t2, t, ':'))
                time2.push_back(stoi(t));
            
            int total_time = (time1[0] * 60 + time1[1]) - (time2[0] * 60 + time2[1]);
            m[load[1]] += total_time;            
        }        
    }
    for(int i = rec.size() - 1;i>=0;i--)
    {
        string t = rec[i][0];
        vector<int> time;
        stringstream ss(t);
        while(getline(ss, t, ':'))
            time.push_back(stoi(t));
        
        int total_time = (23 * 60 + 59) - (time[0] * 60 + time[1]);
        m[rec[i][1]] += total_time;
        rec.erase(rec.begin() + i);
    }
    vector<pair<string, int>> money(m.begin(), m.end());
    sort(money.begin(), money.end(), comp);
    for(auto a : money)
    {
        int value = fees[1];
        if(a.second > fees[0])
        {
            value += (ceil((a.second - fees[0]) / (double)fees[2]) * fees[3]);
        }
            answer.push_back(value);
    }
    return answer;
}