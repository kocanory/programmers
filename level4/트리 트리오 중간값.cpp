#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
unordered_map<int, vector<int>> graph;
unordered_map<int, vector<int>> tree_len;
vector<bool> visited;
int max_step = -1;

void dfs(int vertex, int step)
{
    visited[vertex] = true;
    if(max_step <= step)
    {
        max_step = step;
        tree_len[max_step].push_back(vertex);
    }
    
    for(auto next : graph[vertex])
        if(!visited[next])
            dfs(next, step + 1);
    visited[vertex] = false;
}

void bfs(int vertex)
{
    queue<pair<int, int>> q;
    q.push({vertex, 0});
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        visited[now.first] = true;
        if(now.second >= max_step){
            max_step = now.second;
            tree_len[max_step].push_back(now.first);
        }
        
        for(auto next : graph[now.first])
            if(!visited[next])
                q.push({next, now.second + 1});
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    visited.resize(n + 1);
    
    for(auto e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    dfs(1, 0);
    //bfs(1);
    for(int i = 0;i < 2;i++)
    {
        //visited.clear();
        //visited.resize(n + 1);
        int next = tree_len[max_step][0];
        max_step = -1;
        tree_len.clear();
        dfs(next, 0);
        //bfs(next);
        if(tree_len[max_step].size() > 1) return max_step;        
    }

    return answer = max_step - 1;
}