#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct comp{
    bool operator()(vector<int> a, vector<int> b)
    {
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, comp> pq;
    
    int idx = 0, back = 0;
    while(idx < jobs.size() || !pq.empty())
    {
        if(idx < jobs.size() && jobs[idx][0] <= back)
        {
            pq.push(jobs[idx]);
            idx++;
            continue;
        }
        if(!pq.empty())
        {
            vector<int> now = pq.top();
            pq.pop();
            back += now[1];
            answer += (back - now[0]);
        }
        else
        {
            back = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}