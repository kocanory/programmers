#include <string>
#include <vector>
#include <numeric>

using namespace std;

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    vector<int> arr;
    
    for(auto s : signals){
        arr.push_back(s[0] + s[1] + s[2]);
    }
    
    int t = arr[0];
    
    for(int i = 1;i < arr.size();i++)
        t = lcm(t, arr[i]);
    
    for(int i = 1;i <= t;i++){
        bool flag = true;
        for(auto s : signals){
            int f = s[0] + s[1] + s[2];
            int mod = i % f;

            if(!(s[0] < mod && mod <= s[0] + s[1])){
                flag = false;
                break;
            }
        }
        
        if(flag){
            answer = i;
            break;
        }
    }
    return answer;
}