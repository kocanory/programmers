#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    for(int i = 1;i < sequence.size();i++)
        sequence[i] += sequence[i - 1];
    
    int l = -1, r = 0;
    
    while(r < sequence.size()){
        int val = sequence[r] - (l == -1 ? 0 : sequence[l]);
        
        if(val < k) r++;
        else if(val > k) l++;
        else{
            if(answer.empty() || r - l - 1 < answer[1] - answer[0]) answer = {l + 1, r};
            r++;
        }
    }
    return answer;
}