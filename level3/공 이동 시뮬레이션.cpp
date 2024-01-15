#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

pair<int, int> calcNext(int s, int e, int move, int max)
{
    int nextS = (s == 0 && move > 0) ? 0 : s + move;
    int nextE = (e == max - 1 && move < 0) ? max - 1 : e + move;
    
    if((nextS < 0 || nextS >= max) && (nextE < 0 || nextE >= max)) return {-1, -1};
    
    if(nextS < 0 && nextE >= 0 && nextE < max)
        return {0, nextE};
    
    if(nextE >= max && nextS >= 0 && nextS < max)
        return {nextS, max - 1};
    
    return {nextS, nextE};
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int sx, ex, sy, ey;
    sx = ex = x;
    sy = ey = y;
    
    for(int i = queries.size() - 1;i >= 0;i--)
    {
        int dir = queries[i][0];
        int cnt = queries[i][1];
        
        if(dir == 0 || dir == 1)
        {
            pair<int, int> pos = calcNext(sy, ey, cnt * dy[dir], m);
            if(pos.first == -1) return 0;
            sy = pos.first;
            ey = pos.second;
        }
        else
        {
            pair<int, int> pos = calcNext(sx, ex, cnt * dx[dir], n);
            if(pos.first == -1) return 0;
            sx = pos.first;
            ex = pos.second;
        }
    }
    return (long)(ex - sx + 1) * (long)(ey - sy + 1);
}