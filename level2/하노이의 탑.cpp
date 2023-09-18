#include <string>
#include <vector>

using namespace std;
vector<int> arr(2);


void dfs(vector<vector<int>> &answer, int n, int start, int to, int mid)
{
    if(n == 1)
    {
        arr[0] = start;
        arr[1] = to;
        answer.push_back(arr);
        return;
    }
    dfs(answer, n - 1, start, mid, to);
    
    arr[0] = start;
    arr[1] = to;
    answer.push_back(arr);
    
    dfs(answer, n - 1, mid, to, start);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    dfs(answer, n, 1, 3, 2);
    return answer;
}