#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    string a_str = "", b_str = "";
    
    for(int i = 0;i < 3;i++) {
        a_str += to_string(a);
        b_str += to_string(b);
    }
    
    return a_str > b_str;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    for(auto n : numbers) answer += to_string(n);
    
    return (answer[0] != '0' ? answer : "0");
}