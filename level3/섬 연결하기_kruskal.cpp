#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> parent;
int findParent(int index)
{
    if(parent[index] != index)
        parent[index] = findParent(parent[index]);
    return parent[index];
}

void unionParent(int a, int b)
{
    int n1 = findParent(a);
    int n2 = findParent(b);
    if(n1 < n2)
        parent[n2] = n1;
    else
        parent[n1] = n2;
}

bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), comp);
    for(int i = 0;i < n;i++)
        parent.push_back(i);
    
    for(auto c : costs)
    {
        if(findParent(c[0]) != findParent(c[1]))
        {
            unionParent(c[0], c[1]);
            answer += c[2];
        }
    }
    return answer;
}