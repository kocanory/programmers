#include <string>
#include <vector>

using namespace std;
vector<int> answer(2), discount;

void solve(vector<vector<int>> &users, vector<int> &emoticons){
    if(discount.size() == emoticons.size()){
        int sub = 0, price = 0;
        
        for(auto u : users){
            int val = 0, d = u[0], p = u[1];
            
            for(int i = 0;i < emoticons.size();i++){
                if(discount[i] >= d)
                    val += emoticons[i] * (100 - discount[i]) / 100;
            }

            if(val >= p) sub++;
            else price += val;
        }
        
        
        if(sub >= answer[0]){
            if(sub > answer[0])
                answer = {sub, price};
            else
                answer[1] = max(answer[1], price);
        }
        return;
    }
    for(int i = 40;i >= 10;i -= 10){
        discount.push_back(i);
        solve(users, emoticons);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    solve(users, emoticons);
    return answer;
}