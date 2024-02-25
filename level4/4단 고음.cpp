#include <cmath>
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

using namespace std;

int answer;

void dfs(int num, int plus)
{
    if(num < 3 || ((int)(log(num) / log(3)) * 2) < plus) return;
    if(num == 3){
        if(plus == 2) answer++;
        return;
    }
    if(num % 3 == 0 && plus > 1)
        dfs(num / 3, plus - 2);
    dfs(num - 1, plus + 1);
}

int solution(int n) {
    answer = 0;
    dfs(n - 2, 2);
    return answer;
}