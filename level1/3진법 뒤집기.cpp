#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    string num = "";
    
    while(n){
        num = to_string(n % 3) + num;
        n /= 3;
    }
    
    reverse(num.begin(), num.end());
    
    for(int i = 0;i < num.size();i++)
        answer += pow(3, i) * (num[num.size() - 1 - i] - '0');
    return answer;
}