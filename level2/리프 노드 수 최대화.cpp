#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll answer = 1;

void dfs(ll now, ll used, ll split, ll leaf, int dist_limit, int split_limit){
    if (used > dist_limit) return;
    
    answer = max(answer, now + leaf);
    
    for(int i = 2;i <= 3;i++){
        ll nextSplit = split * i;
        if(nextSplit > split_limit) continue;
        
        ll nextNode = now * i;
        ll remain = dist_limit - used;
        ll nextCur = min(nextNode, remain);
        ll nextLeaf = leaf + (nextNode - nextCur);
    
        dfs(nextCur, used + nextCur, nextSplit, nextLeaf, dist_limit, split_limit);
        }
}

int solution(int dist_limit, int split_limit) {
    dfs(1, 1, 1, 0, dist_limit, split_limit);
    return answer;
}