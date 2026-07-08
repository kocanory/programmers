#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> check(n + 1, 1);
    
    for(int i = 2;i <= n;i++){
        if(!check[i]) continue;
        answer++;
        for(int j = 2 * i;j <= n;j += i)
            check[j] = 0;
    }
    
    return answer;
}