#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, vector<int>> graph;
vector<int> check, stats;

void dfs(int now){
    check[now] = true;
    
    if(now % 2){
        if(graph[now].size() % 2)
            stats[0]++;
        else
            stats[2]++;
    }
    else{
        if(graph[now].size() % 2)
            stats[3]++;
        else
            stats[1]++;
    }
    
    for(auto nxt : graph[now]){
        if(!check[nxt])
            dfs(nxt);
    }
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer{0, 0};
    
    for(auto e : edges){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    check.assign(*max_element(nodes.begin(), nodes.end()) + 1, 0);
    
    for(auto n : nodes){
        if(!check[n]){
            stats.assign(4, 0);
            dfs(n);
            
            if(stats[0] + stats[1] == 1)
                answer[0]++;
            if(stats[2] + stats[3] == 1)
                answer[1]++;                
        }
    }
    
    return answer;
}