#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> name;
    
    for(auto r : record){
        vector<string> tmp;
        stringstream ss(r);
        string s;
        while(ss >> s) tmp.push_back(s);
        
        if(tmp[0] == "Enter" || tmp[0] == "Change") name[tmp[1]] = tmp[2];
    }
    
    for(auto r : record){
        vector<string> tmp;
        stringstream ss(r);
        string s;
        while(ss >> s) tmp.push_back(s);
        
        if(tmp[0] == "Enter") answer.push_back(name[tmp[1]] + "님이 들어왔습니다.");
        else if(tmp[0] == "Leave") answer.push_back(name[tmp[1]] + "님이 나갔습니다.");
    }
    return answer;
}