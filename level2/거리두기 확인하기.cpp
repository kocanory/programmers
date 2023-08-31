#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto p : places)
    {
        vector<pair<int, int>> saram;
        for(int i = 0;i<p.size();i++)
            for(int j = 0;j<p[0].length();j++)
                if(p[i][j] == 'P')
                    saram.push_back({i, j});
        
        bool flag = true;
        for(int i = 0;i<saram.size();i++)
        {
            for(int j = i + 1;j<saram.size();j++)
            {
                int distance = abs(saram[i].first - saram[j].first) + abs(saram[i].second - saram[j].second);
                if(distance <= 2)
                {
                    if(distance == 2)
                    {
                        if(saram[i].first == saram[j].first)
                        {
                            if(p[saram[i].first][(saram[i].second + saram[j].second) / 2] == 'X')
                                continue;
                        }
                        else if(saram[i].second == saram[j].second)
                        {
                            if(p[(saram[i].first + saram[j].first) / 2][saram[i].second] == 'X')
                                continue;
                        }
                        else
                        {
                            if(p[saram[i].first][saram[j].second] == 'X' && p[saram[j].first][saram[i].second] == 'X')
                                continue;
                        }
                    }
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}