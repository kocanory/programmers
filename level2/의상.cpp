#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> check;
    
    for(auto c : clothes)
        check[c[1]]++;
    
    for(auto [k, v] : check)
        answer *= (v + 1);
    
    return answer - 1;
}