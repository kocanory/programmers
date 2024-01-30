#include <string>
#include <vector>
#include <tuple>

using namespace std;
int answer = 1e9;

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {1, 0, -1, 0, 0};

int n, m;

bool notRangedIn(pair<int, int> pos)
{
    return pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m;
}

bool isMovedSamePos(pair<int, int> a, pair<int, int> b)
{
    return a == b;
}

bool isCrossedPos(pair<int, int> a, pair<int, int> a_next, pair<int, int> b, pair<int, int> b_next)
{
    return a == b_next && b == a_next;
}
void dfs(pair<int, int> red, pair<int, int> blue, int count, vector<vector<int>> &maze, vector<vector<bool>> visited[2])
{
    if(maze[red.first][red.second] == 3 && maze[blue.first][blue.second] == 4)
    {
        answer = min(answer, count);
        return;
    }
    
    for(int i = 0;i < 5;i++)
    {
        pair<int, int> next_red = {red.first + dx[i], red.second + dy[i]};
        
        if(notRangedIn(next_red) || (maze[next_red.first][next_red.second] != 3 && visited[0][next_red.first][next_red.second]) || maze[next_red.first][next_red.second] == 5) continue;
        visited[0][next_red.first][next_red.second] = true;
        for(int j = 0;j < 5;j++)
        {
            if(i == 4 && j == 4) break;
            pair<int, int> next_blue = {blue.first + dx[j], blue.second + dy[j]};
            if(notRangedIn(next_blue) || (maze[next_blue.first][next_blue.second] != 4 && visited[1][next_blue.first][next_blue.second]) || maze[next_blue.first][next_blue.second] == 5 || isMovedSamePos(next_red, next_blue) || isCrossedPos(red, next_red, blue, next_blue)) continue;
            visited[1][next_blue.first][next_blue.second] = true;
            dfs(next_red, next_blue, count + 1, maze, visited);
            visited[1][next_blue.first][next_blue.second] = false;
        }
        visited[0][next_red.first][next_red.second] = false;
    }
}

int solution(vector<vector<int>> maze) {
    n = maze.size();
    m = maze[0].size();
    vector<vector<bool>> visited[2];
    pair<int, int> red, blue;
    for(int i = 0;i < 2;i++)
    {
        vector<vector<bool>> temp(maze.size(), vector<bool>(maze[0].size(), false));
        visited[i] = temp;
    }
    
    for(int i = 0;i < maze.size();i++)
    {
        for(int j = 0;j < maze[0].size();j++)
        {
            if(maze[i][j] == 1)
                red = make_pair(i, j);
            if(maze[i][j] == 2)
                blue = make_pair(i, j);
        }
    }
    visited[0][red.first][red.second] = true;
    visited[1][blue.first][blue.second] = true;
    dfs(red, blue, 0, maze, visited);
    return answer = (answer == 1e9) ? 0 : answer;
}