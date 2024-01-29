#include <string>
#include <vector>
#include <cmath>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int ax, int ay, int bx, int by, bool turn, vector<vector<int>> &board)
{
    int x = turn ? ax : bx;
    int y = turn ? ay : by;
    
    vector<int> v;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || !board[nx][ny]) continue;
        
        if(ax == bx && ay == by)
        {
            v.push_back(1);
            continue;
        }
        board[x][y] = 0;
        int res;
        if(turn) res = -1 * dfs(nx, ny, bx, by, !turn, board);
        else res = -1 * dfs(ax, ay, nx, ny, !turn, board);
        if(res >= 0) res++;
        else res--;
        v.push_back(res);
        board[x][y] = 1;
    }
    
    int pMin = 1e9, mMin = 1e9;
    for(auto a : v)
    {
        if(a > 0){
            pMin = min(pMin, a);
        }
        else
        {
            mMin = min(mMin, a);            
        }
    }
    if(pMin == 1e9 && mMin == 1e9) return 0;
    else if(pMin != 1e9) return pMin;
    else if(pMin == 1e9) return mMin;
    else return 0;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    return abs(dfs(aloc[0], aloc[1], bloc[0], bloc[1], true, board));
}