#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
vector<vector<int>> graph;
vector<bool> visited;
unordered_map<int, int> before;
unordered_map<int, int> reserve;

void bfs()
{
    queue<int> q;
    visited[0] = true;
    q.push(0);
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(auto next : graph[now])
        {
            if(visited[next]) continue;
            if(!visited[before[next]]){
                reserve[before[next]] = next;
                continue;
            }
            
            q.push(next);
            visited[next] = true;
            
            if(reserve.find(next) != reserve.end())
            {
                q.push(reserve[next]);
                visited[reserve[next]] = true;
            }
        }
    }       
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
    bfs();
    
    for(auto v : visited)
        if(!v) 
            return false;
    return true;
}