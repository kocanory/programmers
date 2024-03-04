#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int binary_search(vector<long long> &arr, long long x){
    int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    if(idx == 0 && arr[idx] != x) return -1;
    else if(idx == arr.size()) return -1;
    else return idx;
}

int solve(vector<int> &b){
    int maxb = *max_element(b.begin(), b.end());
    int n = b.size();
    
    vector<long long> ps = {0, b[0]};
    
    for(int i = 1;i < n;i++)
        ps.push_back(ps.back() + b[i]);
    
    long long maxe = ceil(log2(ps.back()));
    
    vector<vector<long long>> dp(n, vector<long long> (maxe + 1, 0));
    dp[0][0] = 1;
    
    for(int i = 1;i < n;i++){
        dp[i][0] = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0LL);
        
        for(int e = 1;e < maxe + 1;e++){
            if (dp[i][e - 1] == 0)
                continue;
            
            long long target = ps[i + 1] - b[i] * pow(2, e - 1);
            int jhalf = binary_search(ps, target);
            if(jhalf == -1) continue;
            jhalf = (jhalf - 1 + b.size()) % b.size();
            long double eprime = log2(b[i] / (double)b[jhalf]) + (e - 1);
            if(eprime - (int)eprime != 0 || eprime < 0) continue;
            if(dp[jhalf][(int)eprime] <= 0) continue;
            target = ps[i + 1] - b[i] * pow(2, e);
            
            int jfull = binary_search(ps, target);
            if(jfull == -1) continue;
            
            if(jfull == 0) dp[i][e] = 1;
            else dp[i][e] = accumulate(dp[jfull - 1].begin(), dp[jfull - 1].end(), 0LL) % (1000000007);
        }
    }
    return accumulate(dp.back().begin(), dp.back().end(), 0LL) % (1000000007);
}

vector<int> solution(vector<int> a, vector<int> s) {
    vector<int> answer;
    int start = 0;
    for(auto l : s){
        vector<int> b(a.begin() + start, a.begin() + start + l);
        answer.push_back(solve(b));
        start += l;
    }
    return answer;
}