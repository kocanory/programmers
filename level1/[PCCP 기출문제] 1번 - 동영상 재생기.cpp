#include <string>
#include <vector>

using namespace std;

int convert(string time){
    int minute = stoi(time.substr(0, 2)) * 60;
    int second = stoi(time.substr(3, 2));
    return minute + second;
}

string convert(int time){
    string minute = to_string(time / 60);
    if(minute.length() == 1) minute = '0' + minute;
    
    string second = to_string(time % 60);
    if(second.length() == 1) second = '0' + second;
    return minute + ':' + second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int len = convert(video_len), now = convert(pos), os = convert(op_start), oe = convert(op_end);
    
    for(auto &c : commands){
        if(now >= os && now <= oe) now = oe;
        if(c == "next") now = min(now + 10, len);
        else if(c == "prev") now = max(now - 10, 0);
    }

    if(now >= os && now <= oe) now = oe;
    return convert(now);
}