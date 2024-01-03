#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <climits>

using namespace std;

struct edge{
  int to, weight;  
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, INT_MAX);
    vector<vector<edge>> graph(n + 1);
    
    sort(summits.begin(), summits.end());
    
    for(auto p : paths)
    {
        int from = p[0], to = p[1], weight = p[2];
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    unordered_set<int> summitID;
    for(auto s : summits) summitID.insert(s);

    unordered_set<int> gateID;
    for(auto g : gates) gateID.insert(g);
    
    vector<int> dp(summits.size(), INT_MAX);
    
    for(auto g : gates)
    {
        vector<int> dist(n + 1, INT_MAX);
        vector<int> maxVal(n + 1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[g] = 0;
        maxVal[g] = 0;
        pq.push({0, g});
        
        while(!pq.empty())
        {
            int now_dist = pq.top().first;
            int now_node = pq.top().second;
            pq.pop();
            if(summitID.find(now_node) != summitID.end())
                break;
            for(auto e : graph[now_node])
            {
                int next_node = e.to;
                int weight = e.weight;
                
                if(gateID.find(next_node) != gateID.end())
                    continue;
                if(dist[next_node] > weight)
                {
                    dist[next_node] = weight;
                    maxVal[next_node] = max(maxVal[now_node], dist[next_node]);
                    pq.push({dist[next_node], next_node});
                }
            }
        }
        for(int i = 0;i <summits.size();i++)
            dp[i] = min(dp[i], maxVal[summits[i]]);
    }
    for(int i = summits.size() - 1; i>= 0;i--)
        if(answer[1] >= dp[i])
            answer = {summits[i], dp[i]};
    
    return answer;
}