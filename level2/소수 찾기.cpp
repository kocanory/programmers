#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> check(10000000, 1), num(10000000), visit;

void dfs(string now, string &numbers){
    if(now.size() && check[stoi(now)] && !num[stoi(now)]){
        answer++;
        num[stoi(now)] = true;
    }
    
    for(int i = 0;i < numbers.size();i++){
        if(!visit[i]){
            visit[i] = true;
            dfs(now + numbers[i], numbers);
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    visit.assign(numbers.size(), 0);
    check[0] = 0, check[1] = 0;
    
    for(int i = 2;i < 10000000;i++){
        if(!check[i]) continue;
        for(int j = 2 * i;j < 10000000;j += i)
            check[j] = false;
    }
    dfs("", numbers);
    return answer;
}