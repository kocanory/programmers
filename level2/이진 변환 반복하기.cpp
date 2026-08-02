#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0, deleted = 0, one = 0;
    
    while(s.size() != 1){
        one = 0;
        for(auto a : s){
            if(a == '1') one++;
            else deleted++;
        }
        
        s = "";
        while(one){
            s = to_string(one % 2) + s;
            one /= 2;
        }
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(deleted);
    return answer;
}