#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(auto s : scoville) pq.push(-s); 
    
    while(true){
        if(-pq.top() >= K) return answer;
        if(pq.size() <= 1) return -1;
        
        int f1 = -pq.top(); pq.pop();
        int f2 = -pq.top() * 2; pq.pop();
        pq.push(-(f1 + f2));
        answer++;
    }
    
}