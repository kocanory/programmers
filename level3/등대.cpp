#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(int node, int parent, vector<vector<int>> &arr, vector<bool> &check)
{
    for(auto n : arr[node])
    {
        if(n != parent)
        {
            dfs(n, node, arr, check);
            if(!check[n] && !check[node])
            {
                answer++;
                check[node] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> arr(n + 1);
    vector<bool> check(n + 1, false);
    for(auto l : lighthouse)
    {
        arr[l[0]].push_back(l[1]);
        arr[l[1]].push_back(l[0]);
    }
    dfs(1, 1, arr, check);
    return answer;
}