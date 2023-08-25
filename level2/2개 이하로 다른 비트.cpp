#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(auto a : numbers)
    {
        if(a % 2 == 0)
            answer.push_back(a + 1);
        else
        {
            long long num = a, mul = 1;
            while(num > 0)
            {
                if((num & 1) == 0)
                    break;
                mul *= 2;
                num >>= 1;
            }
            answer.push_back(a + mul - mul / 2);
        }
    }
    return answer;
}