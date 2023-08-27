#include <string>
using namespace std;

bool visit[11][11][4];

int solution(string dirs) {
    int answer = 0;
    int i = 5, j = 5;
    int di[] = {-1, 0, 0, 1};
    int dj[] = {0, -1, 1, 0};
    
    for(auto a : dirs)
    {
        int dir = 0;
        if(a == 'L')
        {
            dir = 0;
        }
        
        else if(a == 'R')
        {
            dir = 3;
        }
        else if(a == 'D')
        {
            dir = 1;
        }
        else if(a == 'U')
        {
            dir = 2;
        }
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if((ni < 0 || ni > 10) || (nj < 0 || nj > 10)) continue;
        if(!visit[i][j][dir] && !visit[ni][nj][3-dir])
        {
            answer++;
            visit[i][j][dir] = true;
            visit[ni][nj][3-dir] = true;
        }
        i = ni;
        j = nj;
    }
    
    return answer;
}