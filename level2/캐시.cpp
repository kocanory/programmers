#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string, int>> cache;
    for(auto a : cities)
    {
        for(int i = 0;i<a.length();i++)
                a[i] = tolower(a[i]);

        if(cacheSize > 0)
        {
            int index = -1;
            for(int i = 0;i<cache.size();i++)
            {
                if(cache[i].first == a)
                {
                    index = i;
                    cache[i].second = 0;
                    answer++;
                }
                else
                    cache[i].second++;
            }

            if(index == -1)
            {
                if(!cache.empty() && cache.size() >= cacheSize)
                {
                    sort(cache.begin(), cache.end(), compare);
                    cache.pop_back();
                }
                cache.push_back(make_pair(a, 0));
                answer += 5;
            }
        }
        else answer+=5;
    }
    return answer;
}