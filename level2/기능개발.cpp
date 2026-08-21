#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    map<int, int> check;
    
    for(int i = 0, days = 0;i < progresses.size();i++){
        days = max(days, (int)ceil((100 - progresses[i]) / (double)speeds[i]));
        check[days]++;
    }
    
    vector<pair<int, int>> arr(check.begin(), check.end());
    
    sort(arr.begin(), arr.end());
    
    for(auto [k, v] : arr)
        answer.push_back(v);
    
    return answer;
}