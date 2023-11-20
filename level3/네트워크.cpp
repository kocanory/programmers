#include <string>
#include <vector>

using namespace std;
int answer = 0;

void dfs(vector<bool> &visit, vector<vector<int>> computers, int index)
{
    if(!visit[index])
    {
        visit[index] = true;
        for(int i = 0;i < computers[index].size(); i++)
        {
            if(i != index && computers[index][i] == 1)
                dfs(visit, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(computers.size(), false);
    for(int i = 0;i < computers.size();i++)
    {
        if(!visit[i])
        {
            answer++;
            dfs(visit, computers, i);   
        }
    }
    return answer;
}