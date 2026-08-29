#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer, nums;
    vector<vector<int>> arr;
    string num = "";
    
    for(int i = 1;i < s.size() - 1;i++){
        if(s[i] == '{'){
            num.clear();
            nums.clear();
        }
        else if(s[i] == '}'){
            nums.push_back(stoi(num));
            arr.push_back(nums);
        }
        else{
            if(s[i] == ','){
                nums.push_back(stoi(num));
                num.clear();
            }
            else num += s[i];
        }
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(auto a : arr){
        for(auto n : a)
            if(find(answer.begin(), answer.end(), n) == answer.end())
                answer.push_back(n);
    }
    
    return answer;
}