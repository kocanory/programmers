#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct comp{
   bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    } 
};

map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, comp>> m;


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(auto c : costs)
    {
        m[c[0]].push({c[1], c[2]});
        m[c[1]].push({c[0], c[2]});
    }
    
    int start = 0;
    visited[start] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> candidate = m[start];
    while(!candidate.empty())
    {
        pair<int, int> route = candidate.top();
        candidate.pop();
        if(!visited[route.first])
        {
            visited[route.first] = true;
            answer += route.second;
            priority_queue<pair<int, int>, vector<pair<int, int>>, comp> end_route = m[route.first];
            while(!end_route.empty())
            {
                candidate.push(end_route.top());
                end_route.pop();
            }
        }
    }
    return answer;
}