#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    map<char, string> word = {{'a', "aya"}, {'y', "ye"}, {'w', "woo"}, {'m', "ma"}};
    
    for(auto b : babbling){
        string back = "-1";
        while(true){
            if(word[b[0]] == "" || word[b[0]] != b.substr(0, word[b[0]].size()) || back == word[b[0]]) break;
            
            back = word[b[0]];
            b = b.substr(word[b[0]].size(), b.size());
        }
        if(!b.size())   answer++;
    }
    
    return answer;
}