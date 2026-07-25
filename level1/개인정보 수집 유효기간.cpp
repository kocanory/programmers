#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

int conv(string date){
    stringstream ss(date);
    string s;
    vector<long long> v;
    
    while(getline(ss, s, '.'))
        v.push_back(stoll(s));
    
    return (v[0] - 1) * 28 * 12 + (v[1] - 1) * 28 + v[2];
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> t;
    
    int now = conv(today);
    
    for(auto a : terms){
        stringstream ss(a);
        string s;
        vector<string> v;
        while(ss >> s)
            v.push_back(s);
        
        t[v[0]] = stoi(v[1]) * 28;    
    }
    
    for(int i = 0;i < privacies.size();i++){
        stringstream ss(privacies[i]);
        string s;
        vector<string> v;
        while(ss >> s)
            v.push_back(s);
        
        if(conv(v[0]) + t[v[1]] <= now)
            answer.push_back(i + 1);
    }
    
    return answer;
}