#include <string>
#include <vector>
#include <map>

using namespace std;

int answer, len;
vector<bool> check;
map<int, vector<int>> graph;

int dfs(int now){
    int cnt = 1;
    
    for(auto nxt : graph[now]){
        if(!check[nxt]){
            check[nxt] = true;
            cnt += dfs(nxt);
        }
    }
    
    answer = min(answer, abs((len - cnt) - cnt));
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    answer = n, len = n;
    check.assign(n + 1, false);
    
    for(auto w : wires){
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    
    check[1] = true;
    dfs(1);
    return answer;
}