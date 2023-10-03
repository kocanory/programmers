#include <string>
#include <vector>
#include <cmath>

using namespace std;

int getNumber(long long n)
{
    if(n == 1) return 0;
    vector<int> arr;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n % i == 0)
        {
            arr.push_back(i);
            if(n / i <= 10000000)
                return n / i;
        }
            
    }
    if(!arr.empty()) return arr.back();
    return 1;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer(end - begin + 1);
    for(long long i = begin, idx = 0;i<=end;i++)
    {
        answer[idx++] = getNumber(i);
    }
    return answer;
}