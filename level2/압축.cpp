#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.first.size() > b.first.size();
}

vector<int> solution(string msg) {
    vector<int> answer;
    vector<pair<string, int>> check;
    
    for(int i = 1;i <= 26;i++)
        check.push_back({string(1, 'A' + i - 1), i});
    
    while(!msg.empty()){
        for(auto [w, i] : check){
            if(msg.find(w) == 0){
                answer.push_back(i);
                msg.erase(0, w.size());
                
                if(!msg.empty()){
                    check.push_back({w + msg[0], check.size() + 1});
                    sort(check.begin(), check.end(), cmp);
                    
                }
                break;
            }
        }
    }
    
    return answer;
}