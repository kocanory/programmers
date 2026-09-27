#include <string>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> check;
    
    for(auto w : weights) check[w]++;
    vector<pair<int, int>> arr(check.begin(), check.end());
    
    for(int i = 0;i < arr.size();i++){
        auto [k1, v1] = arr[i];
        answer += v1 * (long long)(v1 - 1) / 2;
        
        for(int j = i + 1;j < arr.size();j++){
            auto [k2, v2] = arr[j];
            int l = lcm(k1, k2);
            if (l == k1 || l == k2) l *= 2;
            if (l / min(k1, k2) < 5) answer += v1 * (long long)v2;
        }
    }
    
    return answer;
}