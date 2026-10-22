#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1000;
    
    for(int i = 1;i <= s.size();i++){
        vector<string> data;
        
        for(int j = 0;j < s.size();j += i)
            data.push_back(s.substr(j, i));
        
        vector<pair<string, int>> arr;
        string now = data[0];
        int cnt = 1;
        
        for(int k = 1;k < data.size();k++){
            if(now == data[k]) cnt++;
            else{
                arr.push_back({now, cnt});
                now = data[k];
                cnt = 1;
            }
        }
        arr.push_back({now, cnt});
        
        int res = 0;
        for(auto [d, c] : arr)
            res += d.size() + (c == 1 ? 0 : to_string(c).size());
        answer = min(answer, res);
    }
    
    return answer;
}