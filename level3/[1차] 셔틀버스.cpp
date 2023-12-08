#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

int convert_int(string time)
{
    stringstream ss(time);
    string s;
    vector<string> t;
    while(getline(ss, s, ':'))
        t.push_back(s);
    return stoi(t[0]) * 60 + stoi(t[1]);
}

string convert_string(int time)
{
    int h = time / 60;
    int m = time % 60;
    
    string h_str = to_string(h);
    string m_str = to_string(m);
    if(h_str.length() == 1) h_str = "0" + h_str;
    if(m_str.length() == 1) m_str = "0" + m_str;
    return h_str + ":" + m_str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int, vector<int>, greater<int>> pq, last;
    for(auto t : timetable)
        pq.push(convert_int(t));
    
    int now = 9 * 60;
    int count = 1;
    while(n > count)
    {
        int get_in = m;
        while(get_in > 0 && pq.top() <= now + (count - 1) * t)
        {
            pq.pop();
            get_in--;
        }
        count++;
    }
    
    int l;
    while(m > 0 && pq.top() <= now + (count - 1) * t && !pq.empty())
    {
        last.push(pq.top());
        l = pq.top();
        pq.pop();
        m--;
    }
    
    if(m > 0)
    {
        answer = convert_string(now + (count - 1) * t);
    }
    else
    {
        answer = convert_string(l - 1);
    }
    return answer;
}