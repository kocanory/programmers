#include <string>
#include <vector>

using namespace std;

long long factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer, h(n);
    
    for(int i = 0;i < n;i++) h[i] = i + 1;
    k--;
    
    long long div = factorial(n);
    
    for(int i = n;i >= 1;i--){
        div /= i;
        int idx = k / div;
        
        answer.push_back(h[idx]);
        h.erase(h.begin() + idx);
        k -= idx * div;
    }
    
    return answer;
}