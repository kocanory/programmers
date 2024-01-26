#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y, vector<vector<int>> &board, vector<vector<bool>> &check, int isEmpty, vector<vector<pair<int, int>>> &list)
{
    queue<pair<int, int>> q;
    check[x][y] = true;
    q.push({x, y});
    vector<pair<int, int>> arr;
    arr.push_back({0, 0});
    
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i = 0;i < 4;i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board.size()) continue;
            if(!check[nx][ny] && board[nx][ny] == isEmpty)
            {
                check[nx][ny] = true;
                q.push({nx, ny});
                arr.push_back({nx - x, ny - y});
            }
        }
    }
    list.push_back(arr);
}

bool isRotate(vector<pair<int, int>> gp, vector<pair<int, int>> tp)
{
    bool result = false;
    sort(gp.begin(), gp.end());
    for(int i = 0;i < 4;i++)
    {
        sort(tp.begin(), tp.end());
        int nearZeroX = tp[0].first;
        int nearZeroY = tp[0].second;
        
        for(auto &t : tp)
        {
            t.first -= nearZeroX;
            t.second -= nearZeroY;
        }
        
        bool isCollect = true;
        
        for(int j = 0;j < gp.size();j++)
        {
            pair<int, int> gp_now = gp[j];
            pair<int, int> tp_now = tp[j];
            
            if(gp_now.first != tp_now.first || gp_now.second != tp_now.second)
            {
                isCollect = false;
                break;
            }
        }
        
        if(isCollect)
        {
            result = true;
            break;
        }
        else
        {
            for(int j = 0;j <tp.size();j++)
            {
                int tmp = tp[j].first;
                tp[j].first = tp[j].second;
                tp[j].second = -tmp;
            }
        }
    }
    return result;
}

int isCheck(vector<vector<pair<int, int>>> &game, vector<vector<pair<int, int>>> &table)
{
    int result = 0;
    int size = table.size();
    vector<bool> visited(size);
    
    for(int i = 0;i < size;i++)
    {
        vector<pair<int, int>> t_now = table[i];
        for(int j = 0;j < game.size();j++)
        {
            vector<pair<int, int>> g_now = game[j];
            if(t_now.size() == g_now.size() && !visited[j])
            {
                if(isRotate(g_now, t_now))
                {
                    result += t_now.size();
                    visited[j] = true;
                    break;
                }
            }
        }
    }
    return result;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    int size = game_board.size();
    
    vector<vector<bool>> visited_g(size, vector<bool>(size, false));
    vector<vector<bool>> visited_t(size, vector<bool>(size, false));
    vector<vector<pair<int, int>>> gameList, tableList;
    
    for(int i =0;i <size;i++)
    {
        for(int j =0;j <size;j++)
        {
            if(!visited_g[i][j] && game_board[i][j] == 0)
            {
                bfs(i, j, game_board, visited_g, 0, gameList);
            }
            if(!visited_t[i][j] && table[i][j] == 1)
            {
                bfs(i, j, table, visited_t, 1, tableList);
            }
        }
    }
    return answer = isCheck(gameList, tableList);
}