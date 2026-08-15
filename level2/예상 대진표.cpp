#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while(true){
        answer++;
        if(ceil(a / (double)2) == ceil(b / (double)2)) break;
        a = ceil(a / (double)2);
        b = ceil(b / (double)2);
    }

    return answer;
}