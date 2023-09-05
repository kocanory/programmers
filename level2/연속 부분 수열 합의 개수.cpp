#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> arr;
    for(int i = 1;i<=elements.size();i++)
    {
        for(int j = 0;j<elements.size();j++)
        {
            int sum = 0;
            for(int k = 0;k < i;k++)
                sum += elements[(j + k) % elements.size()];
            arr.push_back(sum);
        }
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    return answer = arr.size();
}