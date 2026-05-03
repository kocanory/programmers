#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int size = players.size();
    vector<int> server(size);
    
    for(int i = 0;i < size;i++){
        if(players[i] >= m){
            int n = players[i] / m;
            if(server[i] < n){
                int add = n - server[i];
                answer += add;
                for(int j = 0;j < k;j++){
                    if(i + j < size)
                        server[i + j] += add;
                    else
                        break;
                }
            }
        }
    }
    return answer;
}