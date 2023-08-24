#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

bool check[10000000] = {false, };
bool visit[10000000] = {false, };

void dfs(set<int> &s, string numbers, string num, int index, int count)
{
    if(count == index)
    {
        s.insert(stoi(num));
        return;
    }
    for(int i = 0;i < numbers.length();i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            dfs(s, numbers, num + numbers[i], index, count + 1);
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    for(int i = 1 ;i<=numbers.length();i++)
        dfs(s, numbers, "", i, 0);
    
    int MAX = *max_element(s.begin(), s.end());
    check[0] = true;
    check[1] = true;
    for(int i = 2;i<=sqrt(9999999);i++)
    {
        if(!check[i])
            for(int j = i + i;j<=9999999;j += i)
                check[j] = true;
    }    
    
    for(auto a : s)
        if(!check[a]) answer++;
    return answer;
}