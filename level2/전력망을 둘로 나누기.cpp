#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

using namespace std;

map<int, set<int>> m;
set<int> visited;
int len, Min;

void init(vector<vector<int>> wires)
{
    for(auto a : wires)
    {
        m.insert({a[0], set<int>()});
        m.insert({a[1], set<int>()});
        m[a[0]].insert(a[1]);
        m[a[1]].insert(a[0]);
    }
}

int treeCount(int root)
{
    visited.insert(root);
    int count = 1;
    for(auto a : m[root])
    {
        if(visited.find(a) != visited.end()) continue;
        count += treeCount(a);
    }
    int other = len - count;
    Min = min(Min, abs(count - other));
    return count;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    init(wires);
    Min = n;
    len = n;
    int count = treeCount(wires[0][0]);
    if(count != n) return answer;
    return answer = Min;
}