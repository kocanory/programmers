#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> arr, burger = {1, 2, 3, 1};
    
    for(auto i : ingredient){
        arr.push_back(i);
        if(vector<int>(arr.end() - 4, arr.end()) == burger){
            answer++;
            arr.erase(arr.end() - 4, arr.end());
        }
    }
    return answer;
}