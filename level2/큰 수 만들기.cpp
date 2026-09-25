#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> arr;
    
    for(auto n : number){
        while(k && !arr.empty() && arr.back() < n){
            k--;
            arr.pop_back();
        }
        arr.push_back(n);
    }
    
    for(int i = 0;i < arr.size() - k;i++)
        answer += arr[i];
    
    return answer;
}