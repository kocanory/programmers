#include <vector>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for(int i = 1;i < land.size();i++){
        for(int j = 0;j < 4;j++){
            int val = 0;
            for(int k = 0;k < 4;k++){
                if(j == k) continue;
                val = max(val, land[i - 1][k]);
            }
            land[i][j] += val;
        }
    }

    for(int i = 0;i < 4;i++)
        answer = max(answer, land.back()[i]);
    return answer;
}