#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(auto n : numbers){
        if(!n % 2) answer.push_back(n + 1);
        else{
            long long val = 1;
            while(n > val){
                if((n & val) == 0) break;
                val <<= 1;
            }
            answer.push_back(n + val - val / 2);
        }
    }
    
    return answer;
}