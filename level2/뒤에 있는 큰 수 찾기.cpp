#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1), idx;
    
    for(int i = 0;i < numbers.size();i++){
        while(!idx.empty() && numbers[idx.back()] < numbers[i]){
            answer[idx.back()] = numbers[i];
            idx.pop_back();
        }
        
        idx.push_back(i);
    }
    return answer;
}