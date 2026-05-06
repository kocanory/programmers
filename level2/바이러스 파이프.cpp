#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int answer = 0;
map<int, vector<int>> graph[4];

void move(int start, int pipe, vector<bool> &visited){
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        visited[now] = true;
        
        for(int nxt : graph[pipe][now])
            if(!visited[nxt])
                q.push(nxt);
    }
}

void check(int cnt, int k, int pipe, vector<bool> visited){
    if(cnt == k){
        int sum = 0;
        for(auto v : visited)
            sum += v;
        answer = max(answer, sum);
        return;
    }
    
    vector<bool> visited_copy = visited;
    for(auto [s, e] : graph[pipe]){
        if(visited_copy[s])
            move(s, pipe, visited_copy);
    }
    
    check(cnt + 1, k, 1, visited_copy);
    check(cnt + 1, k, 2, visited_copy);
    check(cnt + 1, k, 3, visited_copy);
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    
    for(auto e : edges){
        graph[e[2]][e[0]].push_back(e[1]);
        graph[e[2]][e[1]].push_back(e[0]);
    }
    
    vector<bool> visited(n + 1);
    visited[infection] = true;
    
    for(int i = 1;i <= 3;i++)
        check(0, k, i, visited);
        
    return answer;
}