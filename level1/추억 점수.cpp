#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(auto p : photo){
        int val = 0;
        for(auto a : p){
            auto pos = find(name.begin(), name.end(), a);
            if(pos != name.end())
                val += yearning[pos - name.begin()];
        }
        answer.push_back(val);
    }
    
    return answer;
}