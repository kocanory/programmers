#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dist = pow(d, 2);
    for(int i = 0;i<=d;i += k)
    {
        answer += floor(sqrt(dist - pow(i, 2))/ k) + 1;
    }
    return answer;
}