#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    vector<int> check(*max_element(citations.begin(), citations.end()) + 1);
    
    for(auto c : citations)
        check[c]++;
    
    for(int i = check.size() - 2;i >= 0;i--)
        check[i] += check[i + 1];
    
    for(int i = check.size() - 1;i >= 0;i--){
        if(check[i] >= i && citations.size() - check[i] <= i){
            answer = i;
            break;
        }
    }
    return answer;
}