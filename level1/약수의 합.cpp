#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1;i <= (int)sqrt(n);i++){
        if(n % i == 0){
            answer += i + (i == sqrt(n) ? 0 : n / i);
        }
    }
    return answer;
}