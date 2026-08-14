#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0, 0};
    map<string, bool> check;
    
    string back = words[0];
    check[back] = true;
    
    for(int i = 1;i < words.size();i++){
        if(words[i].size() == 1 || back[back.size() - 1] != words[i][0] || check[words[i]]){
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        back = words[i];
        check[back] = true;
    }

    return answer;
}