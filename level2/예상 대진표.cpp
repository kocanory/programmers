#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if(a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    while(true)
    {
        answer++;
        if(a == (b - 1) && a % 2) break;
        if(a % 2) a = (a + 1) / 2;
        else a /= 2;
        
        if(b % 2) b = (b + 1) / 2;
        else b /= 2;   
    }

    return answer;
}