#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(vector<string> &maps, pair<int, int> start, pair<int, int> end)
{
    int visit[100][100];
    for(int i = 0;i<maps.size();i++)
        for(int j = 0;j<maps[0].length();j++)
            visit[i][j] = 0;
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0;i<4;i++)
        {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];
            if((next_x >= 0 && next_x < maps.size()) && (next_y >= 0 && next_y < maps[0].length()) && !visit[next_x][next_y] && maps[next_x][next_y] != 'X')
            {
                visit[next_x][next_y] = visit[now.first][now.second] + 1;
                q.push({next_x, next_y});                
            }
        }
    }
    return visit[end.first][end.second];
}



int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> start, end, lever;
    for(int i = 0;i<maps.size();i++)
    {
        for(int j = 0;j<maps[0].length();j++)
        {
            if(maps[i][j] == 'S')
                start = make_pair(i, j);
            else if(maps[i][j] == 'E')
                end = make_pair(i, j);
            else if(maps[i][j] == 'L')
                lever = make_pair(i, j);
        }
    }
    
    int dist_1 = bfs(maps, start, lever);
    int dist_2 = bfs(maps, lever, end);
    if(dist_1 == 0 || dist_2 == 0)
        return -1;
    return answer = dist_1 + dist_2;
}