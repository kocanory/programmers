#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    map<char, char> check = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    
    for(int i = 0;i < s.size();i++){
        vector<char> arr;
        
        for(auto a : s){
            if(arr.empty() || a == '(' || a == '{' || a == '[')
                arr.push_back(a);
            else{
                if(check[arr.back()] == ' ') continue;
                if(a == check[arr.back()])
                    arr.pop_back();
            }
        }
        
        if(arr.empty()) answer++;
        
        s += s[0];
        s.erase(0, 1);
    }
    
    return answer;
}