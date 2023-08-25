#include <string>
#include <vector>

using namespace std;

int MAX = 1000001;
int array[1000001] = {0, };

int convert(int x, int y, int n, int count)
{
    if(array[x] != 0 && array[x] <= count)
        return MAX;
    array[x] = count;
    if(x == y) return count;
    int plus = MAX, three = MAX, two = MAX;
    if(x + n <= y)
        plus = convert(x + n, y, n, count + 1);
    if(x * 2 <= y)
        two = convert(x * 2, y, n, count + 1);
    if(x * 3 <= y)
        three = convert(x * 3, y, n, count + 1);
    return min(plus, min(two, three));
}


int solution(int x, int y, int n) {
    int answer = convert(x, y, n, 0);
    if(answer >= MAX)
        answer = -1;
    return answer;
}