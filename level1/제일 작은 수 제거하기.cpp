#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    auto idx = find(arr.begin(), arr.end(), *min_element(arr.begin(), arr.end()));
    arr.erase(idx);
    if(arr.empty()) arr.push_back(-1);
    return answer = arr;
}