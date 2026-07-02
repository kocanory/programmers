#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1, cnt;i <= number;i++){
        cnt = 0;
        for(int j = 1;j <= sqrt(i);j++)
            if (i % j == 0)
                cnt += (sqrt(i) == j ? 1 : 2);
        answer += (cnt <= limit ? cnt : power);
    }
    
    return answer;
}