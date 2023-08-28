#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &array, vector<vector<int>>maps)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    int start_x = 0, start_y = 0;
    array[start_x][start_y] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(start_x, start_y));
    vector<vector<bool>> visit;
    for(int i = 0;i<maps.size();i++)
    {
        vector<bool> temp(maps[0].size(), false);
        visit.push_back(temp);
    }
    while(!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        for(int i = 0;i<4;i++)
        {
            pair<int, int> next = now;
            next.first += dx[i];
            next.second += dy[i];
            if(next.first >= 0 && next.first < maps.size() && next.second >= 0 && next.second < maps[0].size())
            {
                if(maps[next.first][next.second])
                {
                    if(!visit[next.first][next.second])
                    {
                        if(!(next.first == maps.size() - 1 && next.second == maps[0].size() - 1))
                        {
                            array[next.first][next.second] = array[now.first][now.second] + 1;
                    
                            visit[next.first][next.second] = true;
                            q.push(next);
                        }
                        else
                        {
                            array[next.first][next.second] = array[now.first][now.second] + 1;
                    
                            visit[next.first][next.second] = true;
                            queue<pair<int, int>> reset;
                            q = reset;
                        }
                    }
                }
                
            }            
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<int>> array;
    for(int i = 0;i<maps.size();i++)
    {
        vector<int> temp(maps[0].size(), -1);
        array.push_back(temp);
    }
    bfs(array, maps);
    return answer = (array[maps.size() - 1][maps[0].size() - 1] != -1) ? array[maps.size() - 1][maps[0].size() - 1] : -1;
}