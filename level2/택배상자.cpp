#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> container;
    int index = 0;
    
    for(int i = 1;i<=order.size();i++)
    {
        bool flag = false;
        if(i == order[index])
        {
            index++;
            answer++;
            flag = true;
        }
        while(!container.empty() && container.top() == order[index])
        {
            index++;
            container.pop();
            answer++;
            flag = true;
        }
        if(!flag) container.push(i);
    }
    
    return answer;
}