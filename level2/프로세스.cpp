#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    for(int i = 0;i<priorities.size();i++)
        q.push({priorities[i], i});
    
    sort(priorities.begin(), priorities.end(), greater<>());
    int index = 0;
    while(!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        if(temp.first == priorities[index])
        {
            if(temp.second == location)
                break;
            index++;
        }
        else
            q.push(temp);
    }
    

    return answer = index + 1;
}