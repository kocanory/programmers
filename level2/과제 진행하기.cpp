#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

string conv(string t){
    int res = 0, mul = 60;
    stringstream ss(t);
    string s;
    while(getline(ss, s, ':')){
        res += stoi(s) * mul;
        mul /= 60;
    }
    return to_string(res);
}

bool cmp(vector<string> a, vector<string> b){
    return stoi(a[1]) < stoi(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    for(auto &p : plans)
        p[1] = conv(p[1]);
    
    sort(plans.begin(), plans.end(), cmp);    
    vector<string> now = plans[0];
    vector<pair<string, int>> waiting;
    
    for(int i = 1;i < plans.size();i++){
        if(stoi(now[1]) + stoi(now[2]) <= stoi(plans[i][1])){
            answer.push_back(now[0]);
            int interval = stoi(plans[i][1]) - (stoi(now[1]) + stoi(now[2]));
            
            while(!waiting.empty()){
                auto &[n, t] = waiting.back();
                if(t <= interval){                    
                    interval -= t;
                    answer.push_back(n);
                    waiting.pop_back();
                }
                else{
                    t -= interval;
                    break;
                }
            }
        }
        else
            waiting.push_back({now[0], (stoi(now[1]) + stoi(now[2])) - stoi(plans[i][1])});
        
        now = plans[i];
    }
    
    answer.push_back(now[0]);
    while(!waiting.empty()){
        auto [n, t] = waiting.back();
        waiting.pop_back();
        answer.push_back(n);
    }
    
    return answer;
}