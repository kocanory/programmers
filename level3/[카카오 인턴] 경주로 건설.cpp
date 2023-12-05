#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solution(vector<vector<int>> board) {
    int answer = 1e9;
    int N = board.size();
    vector<vector<vector<int>>> costs(4, vector<vector<int>>(N, vector<int>(N, INT32_MAX)));
    
    queue<tuple<int, int, int>> q;
    for(int d = 1;d <= 2 ;d++)
    {
        q.emplace(0, 0, d);
        costs[d][0][0] = 0;
    }
    
    while(!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        
        for(int nd = 0;nd < 4;nd++)
        {
            int nx = x + dir[d][0], ny = y + dir[d][1];
            int nc = costs[d][x][y] + (nd == d ? 100 : 600);
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != 0 || nc >= costs[nd][nx][ny])
                continue;
            costs[nd][nx][ny] = nc;
            q.emplace(nx, ny, nd);
        }
    }
    
    for(auto cost : costs)
    {
        answer = min(answer, cost[N-1][N-1]);
    }
    return answer;
}