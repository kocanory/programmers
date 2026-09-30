#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int conv(string t){
    stringstream ss(t);
    string s;
    int res = 0, m = 60;
    
    while(getline(ss, s, ':')){
        res += stoi(s) * m;
        m /= 60;
    }
    
    return res;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> arr;
    vector<bool> check(book_time.size());
    
    for(auto b : book_time)
        arr.push_back({conv(b[0]), conv(b[1])});
    
    sort(arr.begin(), arr.end());
    
    while(true){
        bool flag = false;
        int back = -10;
        
        for(int i = 0;i < arr.size();i++){
            if(!check[i] && arr[i].first - back >= 10){
                check[i] = true;
                back = arr[i].second;
                flag = true;
            }
        }
        
        if(!flag) break;
        answer++;
    }
    
    return answer;
}