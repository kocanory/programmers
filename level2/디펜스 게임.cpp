#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    
    for(auto e : enemy){
        if(n < e && k == 0) break;
        pq.push(e);
        
        if(n < e){
            n += pq.top(); 
            pq.pop();
            k--;
        }
        
        n -= e;
        answer++;
    }
    return answer;
}