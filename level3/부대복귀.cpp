#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    map<int, vector<int>> m;
    
    for(auto r : roads)
    {
        m[r[0]].push_back(r[1]);
        m[r[1]].push_back(r[0]);
    }
    
    vector<int> dist(n + 1, 1e9);
    queue<pair<int, int>> q;
    q.push({destination, 0});
    dist[destination] = 0;
    
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        
        if(dist[now.first] < now.second)
            continue;
        
        for(auto next : m[now.first])
        {
            if(dist[next] > now.second + 1)
            {
                dist[next] = now.second + 1;
                q.push({next, now.second + 1});
            }
        }
        
    }
    
    for(auto s : sources)
    {
        int val = (dist[s] == 1e9) ? -1 : dist[s];
        answer.push_back(val);
    }
    return answer;
}