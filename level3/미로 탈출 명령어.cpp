#include <string>
#include <vector>
#include <cmath>

using namespace std;

int minDistance(int x, int y, int r, int c)
{
    return abs(r - x) + abs(c - y);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int dir_x[] = {1, 0, 0, -1};
    int dir_y[] = {0, -1, 1, 0};
    char dir[] = {'d', 'l', 'r', 'u'};
    
    if(((minDistance(x, y, r, c) % 2 == 0) != (k % 2 == 0)) || minDistance(x, y, r, c) > k)
        return "impossible";
    
    while(minDistance(x, y, r, c) != k && k > 0)
    {
        k--;
        
        for(int i = 0;i < 4;i++)
        {
            x += dir_x[i];
            y += dir_y[i];
            
            if(x > 0 && x <= n && y > 0 && y <= m)
            {
                answer += dir[i];
                break;
            }
            else
            {
                x -= dir_x[i];
                y -= dir_y[i];
            }
        }
    }

    while(x != r || y != c)
    {
        k--;
        for(int i = 0;i < 4;i++)
        {
            x += dir_x[i];
            y += dir_y[i];
            
            if(x > 0 && x <= n && y > 0 && y <= m && minDistance(x, y, r, c) == k)
            {
                answer += dir[i];
                break;
            }
            else
            {
                x -= dir_x[i];
                y -= dir_y[i];
            }
        }
    }
    return answer;
}