#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N;
int visit [101][101][4];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool safe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    queue<tuple<int, int, int, int>> q;
    q.push({0, 0, 0, 1});
    visit[0][0][1] = 1;
    
    q.push({0, 0, 1, 3});
    visit[0][1][3] = 1;
    
    while(!q.empty())
    {
        auto [cnt, x1, y1, dir] = q.front();
        q.pop();
        
        int x2 = x1 + dx[dir];
        int y2 = y1 + dy[dir];
        
        if((x1 == N - 1 && y1 == N - 1) || (x2 == N - 1 && y2 == N - 1)) return cnt;
        
        for(int i = 0;i < 4;i++)
        {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            if(!safe(nx1, ny1) || !safe(nx2, ny2)) continue;
            if(board[nx1][ny1] || board[nx2][ny2]) continue;
            
            if(!visit[nx1][ny1][dir])
            {
                visit[nx1][ny1][dir] = 1;
                q.push({cnt + 1, nx1, ny1, dir});
            }
            
            if(!visit[nx2][ny2][(dir + 2) % 4])
            {
                visit[nx2][ny2][(dir + 2) % 4] = 1;
                q.push({cnt + 1, nx2, ny2, (dir + 2) % 4});
            }
            
            if((dir + 1) % 2 == i % 2)
            {
                if(!visit[x1][y1][i])
                {
                    visit[x1][y1][i] = 1;
                    q.push({cnt + 1, x1, y1, i});
                }
            }
        }
    }
    return 0;
}