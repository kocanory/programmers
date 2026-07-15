#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0, val = 0;
    vector<int> num;
    
    for(auto d : dartResult){
        if(isdigit(d)){
            val = val * 10 + (d - '0');
        }
        else{
            if(isupper(d)){
                if(d == 'D') val = pow(val, 2);
                else if(d == 'T') val = pow(val, 3);
                num.push_back(val);
                val = 0;
            }
            else{
                if(d == '*'){
                    num[num.size() - 1] *= 2;
                    if(num.size() > 1)
                        num[num.size() - 2] *= 2;
                }
                else num[num.size() - 1] *= -1;
            }
        }
    }
    
    for(auto n : num) answer += n;
    return answer;
}