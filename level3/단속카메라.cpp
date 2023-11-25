#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> back(2, -30001);
    sort(routes.begin(), routes.end(), comp);
    for(auto r : routes)
    {
        if(r[0] > back[1])
        {
            back = r;
            answer++;
        }
    }
    return answer;
}