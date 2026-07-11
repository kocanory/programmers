#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> check(26, true);
    
    for(auto a : skip)
        check[a - 'a'] = false;
    
    for(auto a : s){
        int cnt = 0, i = 1;
        while(cnt < index){
            if(check[(a - 'a' + i) % 26])
                cnt++;
            i++;
        }
        answer += char((a - 'a' + i - 1) % 26 + 'a');
    }
    
    return answer;
}