#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}


int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end(), comp);
    vector<int> back = targets[0];
    for(int i = 1;i<targets.size();i++)
    {
        if(back[1] <= targets[i][0])
        {
            back = targets[i];
            answer++;
        }
    }
    return answer;
}