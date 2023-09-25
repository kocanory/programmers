#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

map<string, int> m = {{"diamond", 0}, {"iron", 0}, {"stone", 0}};
vector<vector<int>> v = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};

bool comp(vector<int> a, vector<int> b)
{
    if(a[0] == b[0] && a[1] == b[1]) return a[2] > b[2];
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] > b[0];
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    vector<vector<int>> arr;
    int sum = accumulate(picks.begin(), picks.end(), 0);
    int length = min(sum * 5, (int)minerals.size());
    
    for(int i = 0;i<length;i++)
    {
        m[minerals[i]]++;
        if((i + 1) % 5 == 0 || i == minerals.size() - 1)
        {
            vector<int> temp = {m["diamond"], m["iron"], m["stone"]};
            arr.push_back(temp);
            m["diamond"] = 0;
            m["iron"] = 0;
            m["stone"] = 0;
        }
    }
    sort(arr.begin(), arr.end(), comp);
    for(auto a : arr)
    {
        for(int i = 0;i<picks.size();i++)
        {
            if(picks[i] > 0)
            {
                picks[i]--;
                answer += (a[0] * v[i][0] + a[1] * v[i][1] + a[2] * v[i][2]);
                break;
            }
        }
    }
    return answer;
}