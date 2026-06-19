#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer, check(26, -1);
    
    for(int i = 0;i < s.size();i++){
        answer.push_back(check[s[i] - 'a'] == -1 ? -1 : i - check[s[i] - 'a']);
        check[s[i] - 'a'] = i;
    }
    
    return answer;
}