#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    queue<int> q;
    vector<int> dist(n + 1, 0);
   
    q.push(1);
    dist[1] = 1;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(auto &e : edge)
        {
            if(s != e[0] && s != e[1])
                continue;
            
            int g;
            if(s == e[0])
                g = e[1];
            else
                g = e[0];
            
            if(dist[s] == 0 || dist[g] != 0)
                continue;
            dist[g] = dist[s] + 1;
            q.push(g);
        }
    }
    
    int Max = *max_element(dist.begin(), dist.end());
    for(auto &d : dist)
        if(d == Max)
            answer++;
    return answer;
}