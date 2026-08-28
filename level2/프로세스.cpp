#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> arr;
    priority_queue<int> pq;
    
    for(int i = 0;i < priorities.size();i++){
        arr.push_back({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!pq.empty()){
        for(int i = 0;i < arr.size();i++){
            if(arr[i].first == pq.top()){
                pq.pop();
                answer++;
                
                if(arr[i].second == location)
                    return answer;
            }
        }
    }

}