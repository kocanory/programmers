#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int n_global;
vector<vector<int>> graph;
vector<bool> visited;
unordered_map<int, int> before;
unordered_map<int, int> reserve;

void dfs(int n)
{
    if(!visited[before[n]]){
        reserve[before[n]] = n;
        return;
    }
    
    visited[n] = true;
    if(reserve[n] > 0) dfs(reserve[n]);
    
    for(auto g : graph[n])
        if(!visited[g]) dfs(g);
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    
    graph.resize(n);
    for(auto p : path)
    {
        graph[p[0]].push_back(p[1]);
        graph[p[1]].push_back(p[0]);
    }
    
    for(auto o : order)
        before[o[1]] = o[0];
    
    if(before[0] != 0) return false;
    
    visited.resize(n);
    visited[0] = true;
    for(auto g : graph[0])
        dfs(g);
    
    for(auto v : visited)
        if(!v) 
            return false;
    return true;
}