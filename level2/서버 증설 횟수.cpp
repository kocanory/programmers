#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> server(players.size());
    
    for(int i = 0;i < players.size();i++){
        if(players[i] >= m){
            int add = max(0, players[i] / m - server[i]);
            if(add){
                answer += add;
                for(int j = 0;j < k && i + j < server.size();j++)
                    server[i + j] += add;
            }
        }
    }
    return answer;
}