#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, vector<int>> check;

void add(vector<string> &info, string now, int idx){
    if(idx >= 4){
        check[now].push_back(stoi(info.back()));
        return;
    }
    
    add(info, now + info[idx], idx + 1);
    add(info, now + '-', idx + 1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(auto i : info){
        stringstream ss(i);
        string s;
        
        vector<string> arr;
        while(getline(ss, s, ' '))
            arr.push_back(s);
        
        add(arr, "", 0);
    }
    
    for(auto &[k, v] : check)
        sort(v.begin(), v.end());
    
    for(auto q : query){
        stringstream ss(q);
        string s;
        vector<string> arr;
        
        while(getline(ss, s, ' '))
            if(s != "and")
                arr.push_back(s);
        
        int score = stoi(arr.back());
        arr.pop_back();
        
        s = "";
        for(auto a : arr)
            s += a;
        
        answer.push_back(check[s].size() - distance(check[s].begin(), lower_bound(check[s].begin(), check[s].end(), score)));
    }
    
    return answer;
}