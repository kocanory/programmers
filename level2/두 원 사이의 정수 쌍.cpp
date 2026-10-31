#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int i = 1;i <= r1;i++){
        double d1 = sqrt(pow(r1, 2) - pow(i, 2)), d2 = sqrt(pow(r2, 2) - pow(i, 2));
        answer += floor(d2) - ceil(d1) + 1;
    }
    
    for(int i = r1 + 1;i <= r2;i++)
        answer += floor(sqrt(pow(r2, 2) - pow(i, 2))) + 1;
    
    return answer * 4;
}