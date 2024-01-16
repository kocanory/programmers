#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(vector<vector<int>> &board, int r, int c, int x, int y)
{
    queue<tuple<int, int, int>> q;
    q.push({r, c, 0});
    while(!q.empty())
    {
        auto[i, j, d] = q.front();
        if(i == x && j == y) return d;
        q.pop();
        for(int k = 0;k < 4;k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || ni >= 4 || nj < 0 || nj >= 4) continue;
            q.push({ni, nj, d + 1});
            for(int t = 1;;t++){
                int ni = i + t * dx[k], nj = j + t * dy[k];
                if(ni < 0 || ni >= 4 || nj < 0 || nj >= 4)
                {
                    if(t > 1) q.push({ni - dx[k], nj - dy[k], d + 1});
                    break;
                }
                if(!board[ni][nj]) continue;
                q.push({ni, nj, d + 1});
                break;
            }
        }        
    }
    return 0;
}

int f(vector<vector<int>> board, int r, int c, int curr)
{
    int mx = 0;
    for(int i = 0;i < 4;i++)
        for(int j =0 ;j < 4;j++)
            mx = max(mx, board[i][j]);
    
    if(!mx) return 0;
    int ret = 1e9;
    if(!curr)
    {
        for(int i = 0;i < 4;i++)
        {
            for(int j =0;j <4;j++)
            {
                if(!board[i][j]) continue;
                int t = bfs(board, r, c, i, j);
                int tmp = board[i][j];
                board[i][j] = 0;
                ret = min(ret, t + 1 + f(board, i, j, tmp));
                board[i][j] = tmp;
            }
        }
        return ret;
    }
        for(int i = 0;i < 4;i++)
        {
            for(int j =0;j <4;j++)
            {
                if(board[i][j] == curr){
                    int t = bfs(board, r, c, i, j);
                    board[i][j] = 0;
                    return t + 1 + f(board, i, j, 0);
                }
            }
        }
}

int solution(vector<vector<int>> board, int r, int c) {
    return f(board, r, c, 0);
}