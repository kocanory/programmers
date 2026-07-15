#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> check;
    
    for(auto c : completion) check[c]++;
    for(auto p : participant) check[p]--;
    for(auto p : participant){
        if(check[p]){
            answer = p;
            break;
        }
    }
    return answer;
}