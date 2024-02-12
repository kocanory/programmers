#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    vector<int> d(rocks.size() + 1);
    d[0] = rocks[0];
    d[d.size() - 1] = distance - rocks.back();
    
    for(int i = 0;i < rocks.size();i++)
        d[i] = rocks[i] - rocks[i - 1];
    
    int left = 0, right = distance + 1;
    
    while(left < right)
    {
        int mid = (left + right) / 2;
        
        int removed = 0, cur = 0;
        
        for(auto a : d){
            cur += a;
            
            if(cur < mid)
                removed++;
            else
                cur = 0;
        }
        if(removed < n) left = mid + 1;
        else if(removed > n) right = mid;
        else left = mid + 1;
    }
    return answer = left - 1;
}