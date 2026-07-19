#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    map<char, int> check;
    
    for(auto a : X) check[a]++;
    sort(Y.begin(), Y.end(), greater<>());
    
    for(auto a : Y){
        if(answer == "0") break;
        if(check[a]) {
            answer += a;
            check[a]--;
        }
    }
    
    if(answer.empty()) answer = "-1";
    return answer;
}