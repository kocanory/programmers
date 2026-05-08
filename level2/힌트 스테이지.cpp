#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = (int)1e9;
map<int, int> check;

void dfs(int idx, int n, int val, vector<vector<int>> cost, vector<vector<int>> hint){
    if(idx == n - 1){
        for(int i = 0;i < n;i++)
            val += cost[i][min(check[i + 1], n - 1)];
        answer = min(answer, val);
        return;
    }
    
    dfs(idx + 1, n, val, cost, hint);
    
    for(int i = 1;i < hint[idx].size();i++)
        check[hint[idx][i]]++;
    
    dfs(idx + 1, n, val + hint[idx][0], cost, hint);
    
    for(int i = 1;i < hint[idx].size();i++)
        check[hint[idx][i]]--;
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    dfs(0, cost.size(), 0, cost, hint);
    return answer;
}