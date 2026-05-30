#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;  
    long long n = num;
    
    while(n != 1){
        if(answer >= 500){
            answer = -1;
            break;
        }
        if(n % 2) n = n * 3 + 1;
        else n /= 2;
        answer++;
    }
    
    return answer;
}