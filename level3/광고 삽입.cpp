#include <string>
#include <vector>

using namespace std;
int convertTime(string time)
{
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string convertString(int time)
{
    string h = to_string(time / 3600);
    if(h.length() == 1) h = '0' + h;
    time %= 3600;
    string m = to_string(time / 60);
    if(m.length() == 1) m = '0' + m;
    time %= 60;
    string s = to_string(time);
    if(s.length() == 1) s = '0' + s;
    return h + ':' + m + ':' + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int play = convertTime(play_time);
    vector<long long> vec(play + 1);
    for(auto log : logs)
    {
        int start = convertTime(log.substr(0, 8));
        int end = convertTime(log.substr(9, 8));
        vec[start]++;
        vec[end]--;
    }
    for(int i = 1; i <= play; i++) vec[i] += vec[i - 1];
    for(int i = 1; i <= play; i++) vec[i] += vec[i - 1];
    int at = convertTime(adv_time);
    long long res = -1;
    int j = -1;
    for(int i = 0; i + at - 1 <= play;i++)
    {
        long long cnt = vec[i + at -1] - (i ? vec[i - 1] : 0);
        if(cnt <= res) continue;
        res = cnt;
        j = i;
    }
    return convertString(j);
}