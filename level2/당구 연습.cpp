#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> findSym(pair<int, int> start, pair<int, int> ball, int m, int n){
    auto [sx, sy] = start;
    auto [bx, by] = ball;
    vector<pair<int, int>> arr;
    
    if(!(sx == bx && sy < by))
        arr.push_back({bx, n + (n - by)});
    if(!(sx == bx && sy > by))
        arr.push_back({bx, -by});
    if(!(sy == by && sx < bx))
        arr.push_back({m + (m - bx), by});
    if(!(sy == by && sx > bx))
        arr.push_back({-bx, by});
    return arr;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(auto b : balls){
        vector<pair<int, int>> pos = findSym({startX, startY}, {b[0], b[1]}, m, n);
        
        int val = (int)1e9;
        for(auto [px, py] : pos)
            val = min(val, int(pow(startX - px, 2) + pow(startY - py, 2)));
        
        answer.push_back(val);
    }
    
    return answer;
}