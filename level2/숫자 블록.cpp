#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getNum(long long n){
    if(n == 1) return 0;
    
    vector<int> arr;
    for(int i = 2;i <= sqrt(n);i++){
        if(n % i == 0){
            arr.push_back(i);
            if(n / i <= 10000000)
                return n / i;
        }
    }
    
    return (!arr.empty() ? arr.back() : 1);
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    
    for(long long i = begin;i <= end;i++)
        answer.push_back(getNum(i));
    
    return answer;
}