#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(auto t : targets){
        int cnt = 0;
        for(auto c : t){
            int idx = 101;
            for(auto k : keymap){
                auto pos = find(k.begin(), k.end(), c);
                if(pos != k.end()){
                    idx = min(idx, (int)(pos - k.begin() + 1));
                }
            }
            if(idx == 101){
                cnt = -1;
                break;
            }
            cnt += idx;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}