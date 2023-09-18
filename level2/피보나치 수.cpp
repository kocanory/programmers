#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fibonachi[100000] = {0, };

int fibo(int n)
{
    for(int i = 2;i<=n;i++)
        fibonachi[i] = (fibonachi[i - 1] + fibonachi[i - 2]) % 1234567;
}


int solution(int n) {
    int answer = 0;
    fibonachi[0] = 0;
    fibonachi[1] = 1;
    fibo(n);
    return answer = fibonachi[n];
}