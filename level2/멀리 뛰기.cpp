#include <string>
#include <vector>

using namespace std;
long long count[2001] = {0, };
long long solution(int n) {
    long long answer = 0;
    count[1] = 1  % 1234567;
    count[2] = 2  % 1234567;
    for(int i = 3;i<=n;i++)
    {
        for(int j = 1;j <= 2;j++)
            count[i] += (count[i - j])  % 1234567;
    }
    return answer = count[n]  % 1234567;
}