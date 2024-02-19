#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = -1;
    vector<int> flatten;
    for(auto l : land)
        for(auto i : l)
            flatten.push_back(i);
    
    sort(flatten.begin(), flatten.end());
    long long cur_cost = (accumulate(flatten.begin(), flatten.end(), 0LL) - flatten[0] * flatten.size()) * Q;
    long long min_cost = cur_cost;
    for(int i = 1;i < flatten.size();i++)
    {
        if(flatten[i - 1] == flatten[i]) continue;
        long long add_floor = flatten[i] - flatten[i - 1];
        cur_cost -= add_floor * (flatten.size() - i) * Q;
        cur_cost += add_floor * i * P;
        if(cur_cost > min_cost) break;
        min_cost = cur_cost;
    }
    
    return answer = min_cost;
}