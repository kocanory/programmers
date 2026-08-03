#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1;i <= n;i += 2)
        answer += (n % i ? 0 : 1);
    
    return answer;
}