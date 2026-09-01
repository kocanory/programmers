#include <string>
#include <vector>

using namespace std;

int answer = -1;
bool flag = true;
string s = "AEIOU";

void dfs(string now, string word){
    if(now.size() >= 6) return;
    
    answer++;
    if(now == word){
        flag = false;
        return;
    }
    
    for(int i = 0;i < 5;i++){
        dfs(now + s[i], word);
        if(!flag) return;
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}