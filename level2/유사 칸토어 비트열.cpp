#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    for(long long i = l, num;i <= r;i++){
        if(i % 5 == 3) continue;
        num = i;
        while(num > 5 && num % 5 != 3)
            num = ceil(num / (double)5);
        
        if(num % 5 != 3) answer++;
    }
    
    return answer;
}