#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long minTime = 1;
    long long maxTime = *max_element(times.begin(), times.end()) * (long long)n;
    long long answer = maxTime;
    while(minTime <= maxTime)
    {
        long long averageTime = (minTime + maxTime) / 2;
        long long processed = 0;
        for(auto t : times){
            processed += (averageTime / t);
            if(processed >= n) break;
        }
        
        if(processed < n)
            minTime = averageTime + 1;
        else
        {
            answer = min(answer, averageTime);
            maxTime = averageTime - 1;
        }
    }
    return answer;
}