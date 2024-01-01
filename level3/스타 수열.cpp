#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> m;

int solution(vector<int> a) {
    int answer = -1;
    int n = a.size();
    vector<int> check(n + 2, -1);
    a.insert(a.begin(), a.front());
    a.push_back(a.back());
    
    for(int i = 1;i < n + 1;i++)
    {
        if(a[i - 1] != a[i] && check[i - 1] != a[i])
        {
            check[i - 1] = a[i];
            m[a[i]]++;
        }
        else if(a[i + 1] != a[i] && check[i + 1] != a[i])
        {
            check[i + 1] = a[i];
            m[a[i]]++;
        }
        answer = max(answer, 2 * m[a[i]]);
    }
    return answer;
}