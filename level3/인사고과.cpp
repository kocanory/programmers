#include <string>
#include <vector>

using namespace std;
bool check(vector<int> &score, vector<vector<int>> &scores)
{
    for(int i = 1;i < scores.size();i++)
        if(score[0] < scores[i][0] && score[1] < scores[i][1])
            return false;
    return true;
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    for(int i = 1;i < scores.size();i++)
    {
        if(scores[i][0] > scores[0][0] && scores[i][1] > scores[0][1])
            return -1;
        if(scores[i][0] + scores[i][1] > scores[0][0] + scores[0][1])
        {
            if(check(scores[i], scores))
                answer++;
        }
    }

    return answer;
}