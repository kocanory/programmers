#include <string>
#include <vector>

using namespace std;

bool check(vector<int> &diffs, vector<int> &times, long long limit, int level){
    long long sum = times[0];
    for(int i = 1;i < diffs.size();i++){
        if(diffs[i] <= level) sum += times[i];
        else{
            sum += (times[i - 1] + times[i]) * (diffs[i] - level) + times[i];
        }
        if(sum > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int s = 1, e = 100000;
    while(s <= e){
        int mid = (s + e) / 2;
        if(check(diffs, times, limit, mid)){
            answer = mid;
            e = mid - 1;
        }
        else s = mid + 1;
    }
    return answer;
}