#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    int size = 0, del = 0;
    for(auto o : operations)
    {
        if(o == "D 1")
        {
            if(size > 0)
            {
                pq.pop();
                size--;
            }
        }
        else if(o == "D -1")
        {
            if(size > 0)
            {
                size--;
                del++;
            }
        }
        else
        {
            int num = stoi(o.substr(2, o.length() - 1));
            pq.push(num);
            size++;
        }
    }
    
    if(size == 0 || size <= del)
        {
            answer.push_back(0);
            answer.push_back(0);
        }
        else
        {
            int Max = pq.top();
            while(pq.size() > del + 1)
                pq.pop();
            answer.push_back(Max);
            answer.push_back(pq.top());
        }
    return answer;
}