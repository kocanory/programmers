#include <string>
#include <vector>

using namespace std;

void dfs(int &answer, int k, vector<vector<int>> dungeons, vector<bool> visited)
{
    int count = 0;
    for(auto a : visited)
        if(a) count++;
    if(answer < count)
        answer = count;
    
    for(int i = 0;i<dungeons.size();i++)
    {
        if(!visited[i])
        {
            if(k >= dungeons[i][0])
            {
                visited[i] = true;
                k -= dungeons[i][1];
                dfs(answer, k, dungeons, visited);
                k += dungeons[i][1];
                visited[i] = false;
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visited(dungeons.size(), false);
    dfs(answer, k, dungeons, visited);
    return answer;
}