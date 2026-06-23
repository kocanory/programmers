#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto c : commands){
        int s = c[0], e = c[1], i = c[2];
        vector<int> a(array.begin() + s - 1, array.begin() + e);
        sort(a.begin(), a.end());
        answer.push_back(a[i - 1]);
    }
    
    return answer;
}