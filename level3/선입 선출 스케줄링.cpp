#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    if(n <= cores.size()) return n;
    n -= cores.size();
    int left = 1, right = *max_element(cores.begin(), cores.end()) * n;
    while(left < right)
    {
        int mid = (left + right) / 2;
        int works = 0;
        for(auto c : cores)
            works += (mid / c);
        
        if(works < n)
            left = mid + 1;
        else
            right = mid;
    }
    int work_hour = left;
    int remained = 0;
    for(auto c : cores)
        remained += ((work_hour - 1) / c);
    
    remained = n - remained;
    for(int i = 0; i < cores.size();i++)
    {
        if(work_hour % cores[i] == 0)
        {
            remained--;
            if(remained == 0)
                return i + 1;
        }
    }
}