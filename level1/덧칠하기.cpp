#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1, start = section[0];
    
    for(auto s : section){
        if(s >= start + m){
            answer++;
            start = s;
        }
    }
    
    return answer;
}