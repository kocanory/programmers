#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<long long, long long>> v;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    double A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, ADBC = 0, BFED = 0, ECAF = 0, x = 0, y = 0;
    for(int i = 0;i<line.size() - 1;i++)
    {
        A = line[i][0]; B = line[i][1]; E = line[i][2];
        for(int j = i + 1;j<line.size();j++)
        {
            C = line[j][0]; D = line[j][1]; F = line[j][2];
            
            ADBC = A * D - B * C;
            BFED = B * F - E * D;
            ECAF = E * C - A * F;
            if(ADBC != 0)
            {
                x = BFED / ADBC; 
                y = ECAF / ADBC;
                if(x - (long long)x == 0 && y - (long long)y == 0)
                    v.emplace_back(pair<long long, long long>{x, y});
            }  
        }
    }
    
    sort(v.begin(), v.end(), [](auto a, auto b){
        return a.first < b.first;
    });
    
    long long start_x = v[0].first;
    double size_x = v.back().first - v.front().first + 1;
    
    sort(v.begin(), v.end(), [](auto a, auto b){
        return a.second > b.second;
    });
    
    long long end_y = v[0].second;
    double size_y = v.front().second - v.back().second + 1;
    
    string str = "";
    str.append(size_x, '.');
    
    vector<string> result(size_y, str);
    
    for(auto a : v)
        result[end_y - a.second][a.first - start_x] = '*';
        
    return answer = result;
}