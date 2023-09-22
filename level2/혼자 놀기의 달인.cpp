#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(vector<int> cards) {
    int answer = 0;
    priority_queue<int> pq;
    vector<bool> visit(cards.size(), false);
    
    while(true)
    {
        int count = 0;
        int start;
        bool flag = true;
        for(int i = 0;i<cards.size();i++)
        {
            if(visit[i] == false)
            {
                visit[i] = true;
                start = cards[i] - 1;
                flag = false;
                count++;
                break;
            }
        }
        if(flag) break;
        
        while(true)
        {
            if(visit[start] == true)
                break;
            visit[start] = true;
            start = cards[start] - 1;   
            count++;
        }
        pq.push(count);
    }
    
    if(pq.size() == 1) answer = 0;
    else
    {
        int num1 = pq.top();
        pq.pop();
        
        int num2 = pq.top();
        pq.pop();
        
        answer = num1 * num2;
    }
    return answer;
}