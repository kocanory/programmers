#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
void fill(vector<vector<int>> &route, int sx, int sy, int gx, int gy)
{
    for(int i = sx;i <= gx;i++)
    {
        for(int j = sy;j <= gy;j++)
        {
            if(route[i][j] == 2) continue;
            route[i][j] = 2;
            if(i == sx || i == gx || j == sy || j == gy)
                route[i][j] = 1;
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 1e9;
    vector<vector<int>> route(101, vector<int> (101, 0));
    vector<vector<int>> map(101, vector<int> (101, 0));
    vector<vector<bool>> visit(101, vector<bool> (101, false));
    
    for(auto r : rectangle)
        fill(route, r[0] * 2, r[1] * 2, r[2] * 2, r[3] * 2);
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    
    queue<tuple<int, int>> q;
    q.push({2 * characterX, 2 * characterY});
    
    while(!q.empty())
    {
        auto [now_x, now_y] = q.front();
        q.pop();
        if(now_x == 2 * itemX && now_y == 2 * itemY)
            answer = min(answer, map[now_x][now_y]);
        for(int i = 0;i < 4;i++)
        {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];
            
            if(next_x < 0 || next_x > 100 || next_y < 0 || next_y > 100) continue;
            
            if(route[next_x][next_y] != 1 || visit[next_x][next_y]) continue;
            
            q.push({next_x, next_y});
            visit[next_x][next_y] = true;
            map[next_x][next_y] = map[now_x][now_y] + 1;
        }
    }
    
    return answer / 2;
}