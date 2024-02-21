#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, answer = 0;

struct comp{
    bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
    {
        return a.first > b.first;
    }
};

void bfs(int height, vector<vector<bool>> &visited, vector<vector<int>> &land)
{
    int len = n * n;
    queue<pair<int, int>> q;
    priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, comp> pq;
    int count = 1;
    q.push({0, 0});
    visited[0][0] = true;
    while(count < len)
    {
        while(!q.empty())
        {
            pair<int, int> now = q.front();
            q.pop();

            for(int i = 0;i < 4;i++)
            {
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                int cost = abs(land[now.first][now.second] - land[nx][ny]);

                if(cost <= height)
                {
                    count++;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
                else
                {
                    pq.push({cost, {nx, ny}});
                }
            }
        }
        if(count < len)
        {
            int cost = 0;
            pair<int, int> next = {0, 0};
            while(!pq.empty())
            {
                pair<int, pair<int, int>> min_cost = pq.top();
                pq.pop();
                if(!visited[min_cost.second.first][min_cost.second.second])
                {
                    cost = min_cost.first;
                    next = min_cost.second;
                    break;
                }
            }
            answer += cost;
            q.push(next);
            visited[next.first][next.second] = true;
            count++;
        }
    }    
}

int solution(vector<vector<int>> land, int height) {
    n = land.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    bfs(height, visited, land);
    return answer;
}