#include <string>
#include <vector>
#include <map>

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

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m;
    for(auto w : weights)
        m[w]++;
    
    for(auto a : m)
    {
        for(int i = 0;i<a.second-1;i++)
            for(int j = i + 1;j<a.second;j++)
                answer++;
        
        for(auto b : m)
        {
            if(a.first != b.first)
            {
                int l = lcm(a.first, b.first);
                if(l == b.first)
                    l *= 2;
                if(l / min(a.first, b.first) < 5)
                    answer += (a.second * b.second);
            }
        }
        m.erase(a.first);
    }
    return answer;
}