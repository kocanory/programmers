#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> uid;
    map<string, string> m;
    for(auto a : record)
    {
        vector<string> rec;
        stringstream ss(a);
        string s = "";
        while(getline(ss, s, ' '))
            rec.push_back(s);
        
        if(rec[0] == "Enter" || rec[0] == "Leave")
        {
            uid.push_back(make_pair(rec[0], rec[1]));
        }
        if(rec[0] == "Enter" || rec[0] == "Change")
        {
            m[rec[1]] = rec[2];
        }
    }
    for(auto a : uid)
    {
        string str = m[a.second] + "님이 ";
        if(a.first == "Enter")
            str += "들어왔습니다.";
        else
            str += "나갔습니다.";
        answer.push_back(str);
    }
    return answer;
}