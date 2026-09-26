#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0, flag = 0;
    
    while(storey + flag){
        int val = storey % 10 + flag;
        flag = 0;
        
        if(val > 5){
            answer += 10 - val;
            flag = 1;
        }
        else if(val < 5){
            answer += val;
        }
        else{
            answer += val;
            if(storey / 10 && (storey / 10) % 10 >= 5){
                flag = 1;
            }
        }
        
        storey /= 10;
    }
    return answer;
}