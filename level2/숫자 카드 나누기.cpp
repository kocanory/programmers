#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    while(b > 0)
    {
        int n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a = 0;
    if(arrayA.size() == 1)
        a = arrayA[0];
    else
    {
        a = gcd(arrayA[0], arrayA[1]);
        for(int i = 2;i<arrayA.size();i++)
        {
            a = gcd(a, arrayA[i]);
            if(a == 1) break;
        }
    }
    
    int b = 0;
    if(arrayB.size() == 1)
        b = arrayB[0];
    else
    {
        b = gcd(arrayB[0], arrayB[1]);
        for(int i = 2;i<arrayB.size();i++)
        {
            b = gcd(b, arrayB[i]);
            if(b == 1) break;
        }
    }
    
    bool flag_a = true, flag_b = true;
    for(auto arrA : arrayA)
        if(arrA % b == 0)
        {
            flag_a = false;
            break;
        }
    
    for(auto arrB : arrayB)
        if(arrB % a == 0)
        {
            flag_b = false;
            break;
        }
    
    if(!flag_a && !flag_b) answer = 0;
    else answer = max(a, b);
    return answer;
}