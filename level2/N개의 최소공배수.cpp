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

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    for(int i = 0;i<arr.size();i++)
    {
        if(answer == 0)
        {
            answer = lcm(arr[i], arr[i + 1]);
            i++;
        }
        else
        {
            answer = lcm(answer, arr[i]);
        }
    }
    return answer;
}