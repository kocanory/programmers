#include <string>
#include <vector>
#include <map>

using namespace std;
map<int, int> m;

void recursive(int N, int count, int value)
{
    if(count > 8 || (count > 0 && value == 0))
        return;
    m[value] = m[value] ? min(count, m[value]) : count;
    for(int i = N, digit = 1;i <= 111111111;i = i * 10 + N, digit++)
    {
        recursive(N, count + digit, value + i);
        recursive(N, count + digit, value - i);
        recursive(N, count + digit, value * i);
        recursive(N, count + digit, value / i);
    }
}

int solution(int N, int number) {
    int answer = 0;
    for(int i = N, digit = 1;i <= 1111111111;i = i * 10 + N, digit++)
        m[i] = digit;
    recursive(N, 0, 0);
    return answer = (m[number] == 0 ? -1 : m[number]);
}