#include <string>
#include <vector>

using namespace std;
int array[60001] = {0, };
int solution(int n) {
    int answer = 0;
    array[1] = 1;
    array[2] = 2;
    for(int i = 3;i<=n;i++)
        array[i] = (array[i - 1] + array[i - 2]) % 1000000007;
    return answer = array[n] % 1000000007;
}