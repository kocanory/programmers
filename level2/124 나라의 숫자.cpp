#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n){
        n--;
        answer = to_string((int)pow(2, n % 3)) + answer;
        n /= 3;
    }
    
    return answer;
}