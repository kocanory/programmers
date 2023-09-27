#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> arr;
vector<double> integration;
void calc(long long k)
{
    while(true)
    {
        arr.push_back(k);
        if(k <= 1) break;
        if(k % 2) k = k * 3 + 1;
        else k /= 2;
    }
}

void inte()
{
    for(int i = 0;i<arr.size() - 1;i++)
    {
        int Min = min(arr[i], arr[i + 1]);
        double size = Min + abs(arr[i] - arr[i + 1]) / 2.0;
        integration.push_back(size);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    calc(k);
    inte();
    for(auto a : ranges)
    {
        int start = a[0];
        int end = arr.size() + a[1] - 1;
        if(start > end)
            answer.push_back(-1.0);
        else
        {
            double sum = 0.0;
            for(int i = start;i<end;i++)
                sum += integration[i];
            answer.push_back(sum);
        }
    }
    return answer;
}