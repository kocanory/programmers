#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    if(sqrt(n) == (long long)sqrt(n))
        answer = pow((long long)sqrt(n) + 1, 2);
    
    return answer;
}