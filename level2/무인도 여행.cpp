#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void dfs(vector<int> &ans_list, vector<vector<bool>> &visited, int x, int y, vector<vector<int>> map)
{
    if(x < 0 || x > map.size() - 1 || y < 0 || y > map[0].size() - 1)
        return;
    if(map[x][y] == -1) return;
    if(visited[x][y]) return;
    
    visited[x][y] = true;
    
    int val = ans_list.back();
    val += map[x][y];
    ans_list.pop_back();
    ans_list.push_back(val);
    
    dfs(ans_list, visited, x, y + 1, map);
    dfs(ans_list, visited, x, y - 1, map);
    dfs(ans_list, visited, x + 1, y, map);
    dfs(ans_list, visited, x - 1, y, map);
}
vector<int> solution(vector<string> maps) {
    vector<int> answer, ans_list;
    
    vector<vector<int>> map;
    for(int i = 0;i<maps.size();i++)
    {
        vector<int> temp(maps[0].length());
        map.push_back(temp);
    }
    
    for(int i = 0;i<maps.size();i++)
    {
        for(int j = 0;j<maps[0].length();j++)
        {
            if(maps[i][j] == 'X')
                map[i][j] = -1;
            else
                map[i][j] = maps[i][j] - '0';
        }
    }
    
    vector<vector<bool>> visited;
    for(int i = 0;i<maps.size();i++)
    {
        vector<bool> temp(maps[0].length(), false);
        visited.push_back(temp);
    }
    
    for(int i = 0;i<maps.size();i++)
    {
        for(int j = 0;j<maps[0].length();j++)
        {
            if(map[i][j] != -1 && visited[i][j] == false)
            {
                ans_list.push_back(0);
                dfs(ans_list, visited, i, j, map);
            }   
        }
    }
    
    if(ans_list.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        sort(ans_list.begin(), ans_list.end());
        for(auto a : ans_list)
            answer.push_back(a);
    }
    
    return answer;
}