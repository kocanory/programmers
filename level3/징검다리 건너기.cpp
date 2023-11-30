#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &stones, int k, int mid)
{
    int count = 0;
    for(auto s : stones)
    {
        if(s - mid < 0)
            count++;
        else
            count = 0;;
        
        if(count >= k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    vector<int> copy = stones;
    sort(copy.begin(), copy.end());
    int low = 1, high = copy.back();
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(isPossible(stones, k, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return answer = high;
}