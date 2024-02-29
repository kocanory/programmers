#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    int move_distance = 1e9;
    int sum_of_talk_time = 1e9;
    priority_queue<tuple<int, int, int, int>> pq;
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    pq.push({0L, 0L, 0, 0});
    
    while(!pq.empty()){
        auto [talk, move, x, y] = pq.top(); pq.pop();
        move = -move, talk = -talk;
        if(x == m - 1 && y == n - 1){
            if(move_distance > move || (move_distance == move && sum_of_talk_time > talk)){
                move_distance = move;
                sum_of_talk_time = talk;
            }
            continue;
        }
        
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if(time_map[nx][ny] == -1) continue;
            long next_move = move + 1;
            long next_talk = (long)talk + time_map[nx][ny];
            if(next_talk > s) continue;
            if(next_move >= dist[nx][ny]) continue;
            dist[nx][ny] = next_move;
            pq.push({-next_talk, -next_move, nx, ny});
        }
    }
   return {move_distance, sum_of_talk_time};
}