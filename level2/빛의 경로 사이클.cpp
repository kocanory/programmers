#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dir_col[] = {-1, 0, 1, 0};
int dir_row[] = {0, -1, 0, 1};

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row = grid.size();
    int col = grid[0].length();
    int size = row * col;
    
    vector<vector<bool>> visit(size, vector<bool>(4, false));
    
    for(int i = 0; i < 4 * size; i++)
    {
        if(visit[i / 4][i % 4]) continue;
        else visit[i / 4][i % 4] = true;
        
        int now = i;
        int now_row = i / 4 / col;
        int now_col = i / 4 % col;
        int count = 0;
        while(true)
        {
            count++;
            now_col += dir_col[now % 4];
            now_row += dir_row[now % 4];
            
            if(now_col < 0) now_col = col - 1;
            else if(now_col >= col) now_col = 0;
            
            if(now_row < 0) now_row = row - 1;
            else if(now_row >= row) now_row = 0;
            
            int dir = now % 4;
            if(grid[now_row][now_col] == 'L') dir = (dir + 3) % 4;
            else if(grid[now_row][now_col] == 'R') dir = (dir + 1) % 4;
            
            now = ((now_row * col + now_col) * 4) + dir;
            if(now == i)
            {
                answer.push_back(count);
                break;
            }
            if(visit[now / 4][now % 4]) break;
            visit[now / 4][now % 4] = true;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}