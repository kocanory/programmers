#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = wallpaper.size(), minY = wallpaper[0].size(), maxX = 0, maxY = 0;
    
    for(int i = 0;i < wallpaper.size();i++)
        for(int j = 0;j < wallpaper[0].size();j++)
            if(wallpaper[i][j] == '#'){       
                minX = min(minX, i);
                minY = min(minY, j);
                maxX = max(maxX, i);
                maxY = max(maxY, j);
            }
    
    return {minX, minY, maxX + 1, maxY + 1};
}