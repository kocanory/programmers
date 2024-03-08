#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<bool>> visited;
vector<int> arr(500, 0);
int n, m;


void dfs(int x, int y, vector<int> &oil, vector<vector<int>> &land){
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(!land[x][y] || visited[x][y]) return;

    visited[x][y] = true;
    oil[2]++;
    oil[0] = (oil[0] == -1) ? y : ((oil[0] > y) ? y : oil[0]);
    oil[1] = (oil[1] == -1) ? y : ((oil[1] < y) ? y : oil[1]);
    
    for(int i = 0;i < 4;i++){
        dfs(x + dx[i], y + dy[i], oil, land);
    }
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    visited.resize(n, vector<bool>(m, false));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(land[i][j]){
                vector<int> oil(3, -1);
                oil[2] = 0;
                dfs(i, j, oil, land); 
                for(int k = oil[0];k <= oil[1];k++)
                    arr[k] += oil[2];
            }
        }
    }
    sort(arr.begin(), arr.end());
    return answer = arr.back();
}