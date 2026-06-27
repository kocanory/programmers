#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int> pq;
    
    for(auto s : score){
        if(pq.size() < k)
            pq.push(-s);
        else{
            if(-pq.top() < s){
                pq.pop();
                pq.push(-s);
            }
        }
        answer.push_back(-pq.top());
    }
    
    return answer;
}