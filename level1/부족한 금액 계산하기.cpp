#include <algorithm>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = ((long long)count * (count + 1)) / 2 * price;

    return max(answer - money, 0ll);
}