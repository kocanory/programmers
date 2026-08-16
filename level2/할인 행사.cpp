#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> check;
    
    for(int i = 0;i < 10;i++)
        check[discount[i]]++;
    
    bool flag = true;
    for(int i = 0;i < want.size();i++)
        if(check[want[i]] < number[i]){
            flag = false;
            break;
        }
    
    if(flag) answer++;
    
    for(int i = 0;i < discount.size() - 10;i++){
        check[discount[i]]--;
        check[discount[i + 10]]++;
        
        bool flag = true;
        for(int i = 0;i < want.size();i++)
            if(check[want[i]] < number[i]){
                flag = false;
                break;
            }

        if(flag) answer++;
    }
    
    return answer;
}