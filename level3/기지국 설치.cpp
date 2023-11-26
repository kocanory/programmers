#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int start, int end, int w)
{
    int dist = end - start + 1;
    if(dist <= 0)
        return 0;
    if(dist % w == 0)
        return dist / w;
    else
        return dist / w + 1;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    answer += calc(1, max(0, stations[0] - w - 1), 2 * w + 1);
    for(int i = 1;i<stations.size();i++)
        answer += calc(stations[i - 1] + w + 1, stations[i] - w - 1, 2 * w + 1);
    answer += calc(stations[stations.size() - 1] + w + 1, n, 2 * w + 1);

    return answer;
}