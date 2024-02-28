#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> tree;
vector<int> road, stacked, simulation;

int drop(){
    int node = 1;
    while(!tree[node].empty()){
        int next = tree[node][road[node]];
        road[node] = (road[node] + 1) % tree[node].size();
        node = next;
    }
    return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    for(auto e : edges) tree[e[0]].push_back(e[1]);
    
    for(auto &t : tree)
        sort(t.second.begin(), t.second.end());
    
    road.resize(edges.size() + 2, 0);
    stacked.resize(edges.size() + 2, 0);
    vector<bool> check(edges.size() + 2, false);
    
    int cnt = 0;
    for(int i = 0;i < target.size();i++)
        if(target[i] == 0)
        {
            check[i] = true;
            cnt++;
        }           
    
    while(cnt < target.size()){
        int n = drop() - 1;
        simulation.push_back(n);
        stacked[n]++;
        
        if(target[n] < stacked[n]) return {-1};
        if(target[n] <= (stacked[n] * 3)){
            if(!check[n]){
                cnt++; 
                check[n] = true;
            }
        }
    }
    
    for(auto i : simulation){
        int x = max(1, target[i] - (stacked[i] - 1)* 3);
        target[i] -= x; stacked[i]--;
        answer.push_back(x);
    }
    return answer;
}