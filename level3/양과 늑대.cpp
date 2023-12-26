#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> info_g;

int answer = 0;

void dfs(int cur, int sheep, int wolf, queue<int> q) {
    if(info_g[cur] == 0) sheep++;
    else wolf++;
    
    if(wolf >= sheep) return;
    if(answer < sheep) answer = sheep;
    
    for(auto c : graph[cur])
        q.push(c);
    
    for(int i = 0; i < q.size();i++)
    {
        int next = q.front();
        q.pop();
        dfs(next, sheep, wolf, q);
        q.push(next);
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    
    graph.assign(n, vector<int>({}));
    info_g.assign(info.begin(), info.end());
    
    for (int i = 0; i < n-1; i++) {
        int pi = edges[i][0];
        int ci = edges[i][1];
        graph[pi].push_back(ci);
    }
    queue<int> q;
    dfs(0, 0, 0, q);
    return answer;
}