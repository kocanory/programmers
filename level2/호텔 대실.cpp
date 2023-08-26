#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
bool comp(vector<int> a, vector<int> b)
{
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
int convert(string time)
{
    vector<int> t;
    stringstream ss(time);
    string s = "";
    while(getline(ss, s, ':'))
        t.push_back(stoi(s));
    return 60 * t[0] + t[1];
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<bool> visit(book_time.size(), false);
    vector<vector<int>> time;
    for(auto b : book_time)
    {
        vector<int> temp;
        temp.push_back(convert(b[0]));
        temp.push_back(convert(b[1]));
        time.push_back(temp);
    }
    sort(time.begin(), time.end(), comp);
    
    while(true)
    {
        int back = -10;
        for(int i = 0;i<time.size();i++)
        {
            if(!visit[i] && time[i][0] - back >= 10)
            {
                visit[i] = true;
                back = time[i][1];
            }
        }
        if(back == -10)
            break;
        answer++;
    }
    return answer;
}