#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i = 1;i < triangle.size();i++)
    {
        for(int j = 0;j < triangle[i].size();j++)
        {
            if(j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else if(j == triangle[i].size() - 1)
                triangle[i][j] += triangle[i - 1][j - 1];
            else
                triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
    }
    vector<int> result = triangle.back();
    sort(result.begin(), result.end(), greater<int>());
    return answer = result.front();
}