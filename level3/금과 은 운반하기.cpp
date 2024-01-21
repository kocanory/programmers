#include <string>
#include <vector>

using namespace std;

bool isPossible(long time, int a, int b, vector<int> &g, vector<int> &s, vector<int> &w, vector<int> &t)
{
    int n = g.size();
    long long total = 0, totalG = 0, totalS = 0;
    
    for(int i = 0;i < n;i++)
    {
        long long cnt = time / ((long long)2 * t[i]);
        if(time % ((long long)2 * t[i]) >= t[i]) cnt++;
        
        long long temp = min(cnt * w[i], (long long)g[i] + s[i]);
        total += temp;
        totalG += min(temp, (long long)g[i]);
        totalS += min(temp, (long long)s[i]);
    }
    if(total >= a + b && totalG >= a && totalS >= b) return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long right = 400000000000000, left = 0;
    
    while(left < right)
    {
        long long mid = (left + right) / 2;
        if(isPossible(mid, a, b, g, s, w, t)) right = mid;
        else left = mid + 1;
    }
    return left;
}