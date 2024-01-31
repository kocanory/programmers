#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;
map<int, vector<pair<int, int>>> m;

int calc(vector<pair<int, int>> vec, int counsel)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int wait = 0;
    
    for(auto v : vec)
    {
        if(pq.empty() || pq.size() < counsel){
            pq.push(v.second);
        }
        else
        {
            int earlist = pq.top();
            pq.pop();
            
            if(v.first < earlist)
            {
                wait += (earlist - v.first);
                pq.push(earlist + (v.second - v.first));
            }
            else pq.push(v.second);
        }
    }
    return wait;
}

int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 0;
    vector<vector<int>> wait(k + 1, vector<int>(n + 1));
    
    for(auto r : reqs)
        m[r[2]].push_back({r[0], r[0] + r[1]});        
    
    for(int i = 1;i <= k;i++)
    {
        if(m[i].empty()) continue;
        for(int j = 1;j <= (n - k) + 1;j++)
            wait[i][j] = calc(m[i], j);
    }
    
    vector<int> currentCounsel(k + 1, 1);
    int remain = n - k;
    
    while(remain--)
    {
        int maxReduce = 0, correspond = 0;
        for(int i = 1;i <= k;i++)
        {
            int current = currentCounsel[i];
            int waiting = wait[i][current];
            int next = wait[i][current + 1];
            int reduce = abs(next - waiting);
            
            if(reduce > maxReduce)
            {
                maxReduce = reduce;
                correspond = i;
            }
        }
        
        if(maxReduce == 0) break;
        currentCounsel[correspond]++;
    }
    
    for(int i = 1;i <= k;i++)
    {
        if(m[i].empty()) continue;
        int counsel = currentCounsel[i];
        answer += wait[i][counsel];
    }
    return answer;
}