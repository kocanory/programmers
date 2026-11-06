#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visited(cards.size());
    priority_queue<int> pq;
    
    for(int i = 0, cnt, nxt;i < cards.size();i++){
        cnt = 0;
        if(!visited[i]){
            cnt++;
            visited[i] = true;
            nxt = cards[i] - 1;
            
            while(!visited[nxt]){
                cnt++;
                visited[nxt] = true;
                nxt = cards[nxt] - 1;
            }
            
            pq.push(cnt);
        }
    }
    
    if(pq.size() == 1) answer = 0;
    else{
        int f = pq.top(); pq.pop();
        int s = pq.top(); pq.pop();
        answer = f * s;
    }
    return answer;
}