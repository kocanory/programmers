#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i = l;i <= r;i++)
    {
        if(i % 5 == 3) continue;
        long long number = i;
        while(number > 5)
        {
            if(number % 5 == 0)
                number /= 5;
            else
                number = number / 5 + 1;
            if(number % 5 == 3) break;
        }
        if(number % 5 == 3) continue;
        answer++;
    }
    return answer;
}