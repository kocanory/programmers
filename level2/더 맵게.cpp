#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    for(auto a : scoville)
        pq.push(a);
    
    while(pq.top() < K && pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        
        int second = pq.top();
        pq.pop();
        
        int mix = first + second * 2;
        pq.push(mix);
        answer++;
    }
    if(pq.top() < K) return -1;
    return answer;
}