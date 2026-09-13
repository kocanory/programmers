#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> check;
    
    for(int i = 0;i < skill.size();i++)
        check[skill[i]] = i + 1;
    
    for(auto st : skill_trees){
        int flag = true, idx = 0;
        for(auto s : st){
            if(check[s]){
                if(check[s] == idx + 1) idx++;
                else{
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag) answer++;
    }
    return answer;
}