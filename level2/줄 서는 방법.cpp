#include <string>
#include <vector>

using namespace std;;

long long factorial(int n)
{
    if(n == 1)
        return 1;
    return n * factorial(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> human;
    k--;
    for(int i = 1;i<=n;i++)
        human.push_back(i);
    
    long long pre = factorial(n);
    long long div, mod;
    while(human.size() > 1)
    {
        pre /= n;
        div = k / pre;
        mod = k % pre;
        answer.push_back(human[div]);
        human.erase(human.begin() + div);
        k = mod;
        n--;
    }
    answer.push_back(human[0]);
    return answer;
}