#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
bool compare(vector<int> a, vector<int> b)
{
    if(a[n - 1] == b[n - 1]) return a[0] > b[0];
    return a[n - 1] < b[n - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    n = col;
    sort(data.begin(), data.end(), compare);
    bool flag = false;
    for(int i = row_begin - 1;i < row_end;i++)
    {
        int sum = 0;
        for(auto v : data[i])
        {
            sum += (v % (i + 1));
        }
        if(!flag)
        {
            flag = true;
            answer = sum;
        }
        else
        {
            answer = answer ^ sum;
        }
    }
    return answer;
}