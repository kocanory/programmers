#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    while(!deliveries.empty() && !pickups.empty() && deliveries.back() == 0 && pickups.back() == 0)
    {
        deliveries.pop_back();
        pickups.pop_back();
        n--;
    }
    int distance = n;
    
    while(!deliveries.empty() || !pickups.empty())
    {
        answer += distance;
        int box = 0;
        while(!deliveries.empty())
        {
            box += deliveries.back();
            deliveries.pop_back();
            if(box > cap)
            {
                deliveries.push_back(box-cap);
                break;
            }
        }
        
        box = 0;
        while(!pickups.empty())
        {
            box += pickups.back();
            pickups.pop_back();
            if(box > cap)
            {
                pickups.push_back(box-cap);
                break;
            }
        }
        distance = max(deliveries.size(), pickups.size());
    }
    return answer * 2;
}