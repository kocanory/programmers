#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool isExisted(vector<vector<int>> &answer, int x, int y, int a)
{
    for(auto ans : answer)
        if((ans[0] == x) && (ans[1] == y) && (ans[2] == a))
            return true;
    return false;
}

void remove(vector<vector<int>> &answer, int x, int y, int a)
{
    for(int i = 0;i < answer.size();i++)
        if((answer[i][0] == x) && (answer[i][1] == y) && (answer[i][2] == a))
        {
            answer.erase(answer.begin() + i);
            return;
        }
}
bool check(vector<vector<int>> &answer, vector<int> &command)
{
    if(command[2] == 0)
    {
        if(command[1] == 0 || isExisted(answer, command[0], command[1] - 1, 0) || isExisted(answer, command[0] - 1, command[1], 1) || isExisted(answer, command[0], command[1], 1))
            return true;
    }
    else
    {
        if(isExisted(answer, command[0], command[1] - 1, 0) || isExisted(answer, command[0] + 1, command[1] - 1, 0) || (isExisted(answer, command[0] - 1, command[1], 1) && isExisted(answer, command[0] + 1, command[1], 1)))
            return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(auto b : build_frame)
    {
        if(b[3] == 1)
        {
            if(check(answer, b))
            {
                b.pop_back();
                answer.push_back(b);
            }
        }
        else
        {
            remove(answer, b[0], b[1], b[2]);
            for(auto a : answer)
            {
                if(!check(answer, a))
                {
                    b.pop_back();
                    answer.push_back(b);
                    break;
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}