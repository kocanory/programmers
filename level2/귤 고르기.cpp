#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> cnt;
    
    for(auto t : tangerine)
        cnt[t]++;
    
    vector<pair<int, int>> arr(cnt.begin(), cnt.end());
    sort(arr.begin(), arr.end(), cmp);
    
    for(auto a : arr){
        if(k <= 0) break;
        k -= a.second;
        answer++;
    }
    
    return answer;
}