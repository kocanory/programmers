#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n % 2) return 0;
    if(n == 2) return 3;
    if(n == 4) return 11;
    long long answer = 0, sum = 3, back = 11;
    for(int i = 6;i<=n;i+=2)
    {
        answer = (3 * back + 2 * sum + 2) % 1000000007;
        sum += back;
        back = answer;
    }
    return answer;
}