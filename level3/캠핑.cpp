#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
    int answer = 0;
    sort(data.begin(), data.end());
    for(int i = 0; i < data.size();i++)
    {
        for(int j = i + 1;j < data.size();j++)
        {
            if(data[i][0] == data[j][0] || data[i][1] == data[j][1]) continue;
            
            bool check = true;
            for(int k = i + 1;k < data.size();k++)
            {
                if(data[i][0] < data[k][0] && data[k][0] < data[j][0] && max(data[i][1], data[j][1]) > data[k][1] && min(data[i][1], data[j][1]) < data[k][1])
                {
                    check = false;
                    break;
                }
            }
            if(check) answer++;
            
        }
    }
    return answer;
}