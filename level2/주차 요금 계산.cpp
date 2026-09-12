#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int conv(string t){
    vector<int> tmp;
    stringstream ss(t);
    string s;
    while(getline(ss, s, ':'))
        tmp.push_back(stoi(s));
    return tmp[0] * 60 + tmp[1];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> check, acc;
    
    for(auto r : records){
        vector<string> tmp;
        stringstream ss(r);
        string s;
        
        while(ss >> s)
            tmp.push_back(s);
        
        if(tmp[2] == "IN") check[tmp[1]] = conv(tmp[0]);
        else{
            acc[tmp[1]] += conv(tmp[0]) - check[tmp[1]];
            check[tmp[1]] = -1;
        }
    }
    
    for(auto [k, v] : check)
        if(v != -1)
            acc[k] += conv("23:59") - check[k];
    
    vector<pair<string, int>> arr(acc.begin(), acc.end());
    sort(arr.begin(), arr.end());
    
    for(auto [k, v] : arr){
        int f = fees[1] + max(0, (int)ceil((v - fees[0]) / double(fees[2])) * fees[3]);
        answer.push_back(f);
    }
    return answer;
}