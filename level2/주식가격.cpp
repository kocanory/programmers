#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size()), arr;
    
    for(int i = 0;i < prices.size();i++){
        while(!arr.empty() && prices[arr.back()] > prices[i]){
            answer[arr.back()] = i - arr.back();
            arr.pop_back();
        }
        arr.push_back(i);
    }
    
    while(!arr.empty()){
            answer[arr.back()] = prices.size() - arr.back() - 1;
            arr.pop_back();
        }
    
    return answer;
}