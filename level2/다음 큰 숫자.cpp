#include <string>
#include <vector>

using namespace std;

int check(int n){
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    
    int cnt = check(n);
    n++;
    
    while(true){
        if(check(n) == cnt){
            answer = n;
            break;
        }
        n++;
    }

    return answer;
}