#include <string>
#include <vector>
#include <cmath>

using namespace std;
long long answer = 0;

void dfs(vector<long long> &sum, vector<vector<int>> &graph, int parent, int now)
{
    for(auto &n : graph[now])
    {
        if(n != parent)
            dfs(sum, graph, now, n);
    }
    
    sum[parent] += sum[now];
    answer += abs(sum[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> sum;
    vector<vector<int>> graph(a.size());
    
    for(auto n : a)
        sum.push_back(n);
    
    for(auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    dfs(sum, graph, 0, 0);
    
    return answer = (sum[0] == 0) ? answer : -1;
    
}