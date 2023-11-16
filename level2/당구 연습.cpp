#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> checkSymmetric(pair<int, int> board, pair<int, int> start, pair<int, int> ball)
{
    vector<pair<int, int>> sym;
    if(!(start.first == ball.first && start.second > ball.second))
        sym.push_back({ball.first, ball.second * -1});
    if(!(start.first == ball.first && start.second < ball.second))
        sym.push_back({ball.first, board.second + (board.second - ball.second)});
    if(!(start.second == ball.second && start.first > ball.first))
        sym.push_back({ball.first * -1, ball.second});
    if(!(start.second == ball.second && start.first < ball.first))
        sym.push_back({board.first + (board.first - ball.first), ball.second});

    return sym;
}

int calcDistance(pair<int, int> start, pair<int, int> ball)
{
    return (int)(pow(start.first - ball.first, 2)) + (int)(pow(start.second - ball.second, 2));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto a : balls)
    {
        int Min = 1e9;
        vector<pair<int, int>> sym = checkSymmetric({m, n}, {startX, startY}, {a[0], a[1]});
        for(auto s : sym)
            Min = min(Min, calcDistance({startX, startY}, {s.first, s.second}));
        answer.push_back(Min);
    }
    return answer;
}