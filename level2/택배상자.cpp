#include <string>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    int answer = 0, idx = 0;
    vector<int> sub;
    
    for(int i = 1, flag;i <= order.size();i++){
        flag = false;
        if(order[idx] == i){
            idx++;
            answer++;
            flag = true;
        }
        
        while(!sub.empty() && sub.back() == order[idx]){
            idx++;
            sub.pop_back();
            answer++;
            flag = true;
        }
        
        if(!flag) sub.push_back(i);
        
    }
    return answer;
}