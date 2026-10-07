#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<map<string, int>> food(11);
vector<bool> visited;

void dfs(string order, string now, int idx){
    if(now.size() > 10) return;
    
    food[now.size()][now]++;
    
    for(int i = idx;i < order.size();i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(order, now + order[i], i + 1);
            visited[i] = false;
        }
    }
}

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(auto o : orders){
        visited.assign(o.size(), false);
        sort(o.begin(), o.end());
        dfs(o, "", 0);
    }
    
    for(auto c : course){
        if(food[c].size() == 0) continue;
        vector<pair<string, int>> tmp(food[c].begin(), food[c].end());
        sort(tmp.begin(), tmp.end(), cmp);
        
        if(tmp[0].second <= 1) continue;
        for(auto [k, v] : tmp)
            if (v == tmp[0].second)
                answer.push_back(k);
    }
    sort(answer.begin(), answer.end());
    return answer;
}