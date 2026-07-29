#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> arr;
    
    for(auto a : s){
        if(a == '(') arr.push_back(a);
        else{
            if(arr.empty()) return false;
            arr.pop_back();
        }
    }
    
    if(!arr.empty()) return false;
    return answer;
}