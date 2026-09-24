#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, sum = 0, idx = 0;
    queue<pair<int, int>> q;
    
    while(true){
        if(!q.empty() && answer - q.front().first >= bridge_length){
            sum -= q.front().second;
            q.pop();
        }
        
        if(q.empty() && idx == truck_weights.size())
            break;
        
        if(idx < truck_weights.size() && q.size() < bridge_length && sum + truck_weights[idx] <= weight){
            sum += truck_weights[idx];
            q.push({answer, truck_weights[idx++]});
        }
        answer++;
    }
    return answer;
}