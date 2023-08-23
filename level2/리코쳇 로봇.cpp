#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
void BFS(int x, int y, vector<string> board, vector<vector<string>> &array)
{
    int m = board.size();
    int n = board[0].length();
    vector<vector<bool>> visit;
    for(int i = 0;i<m;i++)
    {
        vector<bool> temp(n);
        visit.push_back(temp);
    }
    array[x][y] = "0";
    int sx = x, sy = y;
    int direction_x[] = {1, 0, -1, 0};
    int direction_y[] = {0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            pair<int, int> now = p;
            while(true)
            {
                now.first += direction_x[i];
                now.second += direction_y[i];
                if(now.first >= 0 && now.first < board.size() && now.second >= 0 && now.second < board[0].length())
                {
                    if(board[now.first][now.second] == 'D')
                    {
                        now.first -= direction_x[i];
                        now.second -= direction_y[i];
                        break;
                    }
                }
                else
                {
                        now.first -= direction_x[i];
                        now.second -= direction_y[i];
                        break;
                }
            }
            if(p.first == now.first && p.second == now.second) continue;
            if(!visit[now.first][now.second])
            {
                if(board[now.first][now.second] == 'G')
                {
                    array[now.first][now.second] = to_string(stoi(array[p.first][p.second]) + 1);
                    visit[now.first][now.second] = true;
                    queue<pair<int, int>> temp;
                    swap(q, temp);
                }
                else
                {
                    array[now.first][now.second] = to_string(stoi(array[p.first][p.second]) + 1);
                    visit[now.first][now.second] = true;
                    q.push(now);                    
                }
            }
            
        }
    }
}
int solution(vector<string> board) {
    int answer = 0;
    int sx = 0, sy = 0, ex = 0, ey = 0;
    vector<vector<string>> array;
    for(int i = 0;i<board.size();i++)
    {
        vector<string> temp(board[0].length());
        array.push_back(temp);
    }
    for(int i = 0;i<board.size();i++)
    {
        for(int j = 0;j<board[0].length();j++)
        {
            string temp = "";
            temp += board[i][j];
            array[i][j] = temp;
            if(board[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            if(board[i][j] == 'G')
            {
                ex = i;
                ey = j;
            }
        }
    }
    
    BFS(sx, sy, board, array);
    return answer = (array[ex][ey] == "G") ? -1 : stoi(array[ex][ey]);
}