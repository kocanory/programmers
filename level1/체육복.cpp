#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n + 1, 0);
    
    for(auto l : lost) check[l]--;
    for(auto r : reserve) check[r]++;
    
    for(int i = 1;i <= n;i++){
        if(i > 1){
            if(check[i] > 0 && check[i - 1] < 0){
                check[i]--;
                check[i - 1]++;
            }
        }
        if(i < n){
            if(check[i] > 0 && check[i + 1] < 0){
                check[i]--;
                check[i + 1]++;
            }
        }
    }
    for(int i = 1;i <= n;i++)
        if(check[i] >= 0)
            answer++;
    return answer;
}