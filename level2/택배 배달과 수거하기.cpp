#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(!deliveries.empty() && !pickups.empty() && deliveries.back() == 0 && pickups.back() == 0){
        deliveries.pop_back();
        pickups.pop_back();
    }
    
    while(!deliveries.empty() || !pickups.empty()){
        answer += max(deliveries.size(), pickups.size());
        int dSum = 0, pSum = 0;
        while(!deliveries.empty() && dSum <= cap){
            dSum += deliveries.back();
            deliveries.pop_back();
            if(dSum > cap)
                deliveries.push_back(dSum - cap);
        }
        
        while(!pickups.empty() && pSum <= cap){
            pSum += pickups.back();
            pickups.pop_back();
            if(pSum > cap)
                pickups.push_back(pSum - cap);
        }
    }
    return answer * 2;
}