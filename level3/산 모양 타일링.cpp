#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    a[0] = 0;
    b[0] = 1;
    
    for(int i = 1;i <= n;i++)
    {
        if(tops[i - 1]){
            a[i] = (a[i - 1] + b[i - 1]) % 10007;
            b[i] = (2 * a[i - 1] + 3 * b[i - 1]) % 10007;
        }
        else
        {
            a[i] = (a[i - 1] + b[i - 1]) % 10007;
            b[i] = (a[i - 1] + 2 * b[i - 1]) % 10007;
        }
    }    
    return (a[n] + b[n]) % 10007;
}