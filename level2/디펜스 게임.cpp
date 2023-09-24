#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i =0;i<enemy.size();i++)
    {
        if(n < enemy[i] && k == 0) break;
        pq.push(enemy[i]);
        if(n < enemy[i])
        {
            if(!pq.empty())
            {
                n += pq.top();
                pq.pop();
            }
            k--;
        }
        n -= enemy[i];
        answer++;
    }
    return answer;
}