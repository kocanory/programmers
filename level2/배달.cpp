#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    priority_queue<pair<int, int>> pq;
    vector<int> dist(N + 1, 1e9);
    map<int, vector<pair<int, int>>> graph;
    
    for(auto r : road){
        graph[r[0]].push_back({r[1], r[2]});
        graph[r[1]].push_back({r[0], r[2]});
    }
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto[cost, now] = pq.top();
        cost = -cost;
        pq.pop();
        
        if(cost > dist[now]) continue;
        
        for(auto [nxt, ncost] : graph[now]){
            ncost += cost;
            if(ncost <= K && ncost < dist[nxt]){
                dist[nxt] = ncost;
                pq.push({-ncost, nxt});
            }
        }
    }
    
    for(auto d : dist)
        if(d <= K)
            answer++;
    
    return answer;
}