#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sum1 = 0, sum2 = 0, count = 0, size = queue1.size();
    queue<int> q1, q2;
    for(int i = 0;i<size;i++)
    {
        sum1 += queue1[i];
        q1.push(queue1[i]);
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    int sum = sum1 + sum2;
    while(true)
    {
        if(count > 4 * size)
        {
            answer = -1;
            break;
        }
        if(sum1 > sum2)
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
            count++;
        }
        else if(sum1 < sum2)
        {
            sum2 -= q2.front();
            sum1 += q2.front();
            q1.push(q2.front());
            q2.pop();
            count++;
        }
        else
        {
            answer = count;
            break;
        }
    }
    return answer;
}