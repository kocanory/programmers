#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int, int>> food_pair;
    for(int i = 0;i < food_times.size();i++)
        food_pair.push_back({food_times[i], i + 1});
    sort(food_pair.begin(), food_pair.end());
    
    int back = 0;
    for(int i = 0;i < food_pair.size();i++)
    {
        if(back == food_pair[i].first) continue;
        long long spend = (food_pair[i].first - back) * (food_pair.size() - i);
        if(k >= spend) 
        {
            k -= spend;
            back = food_pair[i].first;
        }
        else
        {
            k %= (food_pair.size() - i);
            sort(food_pair.begin() + i, food_pair.end(), comp);
            return food_pair[i + k].second;
        }
    }
    return -1;
}