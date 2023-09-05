#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    for(auto a : tangerine)
        m[a]++;
    vector<pair<int,int>> arr (m.begin(), m.end());
    sort(arr.begin(), arr.end(), comp);
    
    int sum = 0;
    for(auto a : arr)
    {
        sum += a.second;
        answer++;
        if(sum >= k) break;
    }
    return answer;
}