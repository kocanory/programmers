#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left, cnt;i <= right;i++){
        cnt = 0;
        for(int j = 1;j <= sqrt(i);j++){
            if(i % j == 0)
                cnt += (i / j != j ? 2 : 1);
        }
        answer += (cnt % 2 ? -i : i);
    }
    
    return answer;
}