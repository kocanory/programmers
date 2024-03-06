#include <string>
#include <vector>

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int solution(vector<vector<string>> board, int h, int w) {
    
    int answer = 0;
    for(int i = 0;i < 4;i++){
        int nx = h + dx[i];
        int ny = w + dy[i];
        if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size()) continue;
        if(board[h][w] == board[nx][ny]) answer++;
    }
    return answer;
}