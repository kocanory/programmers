#include <string>
#include <vector>

using namespace std;

bool check(int mid, long long limit, vector<int> diffs, vector<int> times){
    long long sum = 0;
    for(int i = 0;i < diffs.size();i++){
        sum += (mid >= diffs[i] ? times[i] : (times[i] + times[i - 1]) * (diffs[i] - mid) + times[i]);
        if(sum > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0, s = 1, e = 100000;
    
    while(s <= e){
        int mid = (s + e) / 2;
        if(check(mid, limit, diffs, times)){
            answer = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    return answer;
}