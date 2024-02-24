#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;

map<int, vector<int>> tree;
vector<vector<int>> dp;
vector<int> s;


void dfs(int v)
{
    if(tree[v].empty()){
        dp[v][0] = s[v];
        dp[v][1] = 0;
        return;
    }
    int Min = INT_MAX;
    dp[v][0] = s[v];
    for(auto c : tree[v]){
        dfs(c);
        dp[v][0] += min(dp[c][0], dp[c][1]);
        Min = min(Min, dp[c][0] - dp[c][1]);
    }
    if(Min < 0) Min = 0;
    dp[v][1] = dp[v][0] + Min - s[v];
}

int solution(vector<int> sales, vector<vector<int>> links) {
    dp.resize(sales.size() + 1, vector<int>(2));
    s.push_back(0);
    for(auto a : sales) s.push_back(a);
    for(auto l : links) tree[l[0]].push_back(l[1]);
    dfs(1);
    return min(dp[1][0], dp[1][1]);
}