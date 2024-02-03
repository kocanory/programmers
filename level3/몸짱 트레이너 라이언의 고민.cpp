#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int getDistance(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

bool canFurther(pair<int, int> coord, int maxDistance, vector<pair<int, int>> &people)
{
    for(auto &p : people)
    {
        if(getDistance(coord, p) < maxDistance)
            return false;
    }
    return true;
}

int getMaxUser(vector<vector<int>> timetable)
{
    sort(timetable.begin(), timetable.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(timetable[0][1]);
    
    for(int i = 1;i < timetable.size();i++)
    {
        pq.push(timetable[i][1]);
        if(pq.top() < timetable[i][0]) pq.pop();
    }
    return pq.size();
}

int solution(int n, int m, vector<vector<int>> timetable) {
    
    int maxCrowd = getMaxUser(timetable);
    if(maxCrowd == 1) return 0;
    
    for(int distance = 2 * n - 2;distance > 0;distance--)
    {
        for(int x =0;x < n;x++)
        {
            for(int y = 0;y < n;y++)
            {
                if(x != 0 && y != 0) continue;
                vector<pair<int, int>> people{{x, y}};
                for(int x2 = x;x2 < n;x2++)
                {
                    for(int y2 = 0;y2 < n;y2++)
                    {
                        if(x2 == x && y2 == y) continue;
                        if(canFurther({x2, y2}, distance, people)) people.push_back({x2, y2});
                        if(people.size() == maxCrowd) return distance;
                    }
                }
            }
        }
    }
}