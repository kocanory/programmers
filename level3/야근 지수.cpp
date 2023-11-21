#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(auto w : works)
        pq.push(w);
    while(n > 0)
    {
        if(pq.top() == 0)
            return 0;
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
        n--;
    }

    int size = pq.size();
    for(int i = 0;i < size;i++)
    {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}