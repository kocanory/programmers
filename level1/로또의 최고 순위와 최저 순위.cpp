#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zcnt = 0, wcnt = 0;
    
    for(auto l : lottos){
        if(l == 0) zcnt++;
        else{
            if(find(win_nums.begin(), win_nums.end(), l) != win_nums.end()) wcnt++;
        }
    }
    
    answer.push_back(min(6 - (zcnt + wcnt) + 1, 6));
    answer.push_back(min(6 - wcnt + 1, 6));
    return answer;
}