#include <string>
#include <vector>

using namespace std;

int answer = -1;

void dfs(int cnt, int remains, vector<vector<int>> dungeons, vector<bool> visited){
    answer = max(answer, cnt);
    
    for(int i = 0;i < dungeons.size();i++){
        if(!visited[i] && remains >= dungeons[i][0]){
            visited[i] = true;
            dfs(cnt + 1, remains - dungeons[i][1], dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons, vector<bool>(dungeons.size()));
    return answer;
}