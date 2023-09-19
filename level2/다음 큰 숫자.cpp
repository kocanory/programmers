#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0, origin = n;
    while(n)
    {
        cnt += (n & 1);
        n >>= 1;
    }
    
    while(true)
    {
        int num = origin + 1;
        int count = 0;
        while(num)
        {
            count += (num & 1);
            num >>= 1;
        }
        if(count == cnt)
        {
           answer = origin + 1;
           break;
        }
        origin++;
    }
    
    return answer;
}