#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<bool> check;
int answer = 0, n = 0;

void dfs(int cnt, int idx, int val, vector<int> &nums){
    if(cnt == 3){
        if(check[val]) answer++;
        return;
    }
    for(int i = idx;i < nums.size();i++)
        dfs(cnt + 1, i + 1, val + nums[i], nums);
}

int solution(vector<int> nums) {
    for(auto a : nums) n += a;
    
    check.assign(n + 1, true);
    
    for(int i = 2;i <= sqrt(n);i++){
        if(!check[i]) continue;
        for(int j = i * i;j <= n;j += i)
            check[j] = false;
    }
    
    dfs(0, 0, 0, nums);
    return answer;
}