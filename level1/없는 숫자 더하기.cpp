#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    vector<bool> check(10);
    
    for(int n : numbers)
        check[n] = true;
    
    for(int i = 0;i <= 9;i++)
        if(!check[i])
            answer += i;
    
    return answer;
}