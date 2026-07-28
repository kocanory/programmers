#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> check;
    map<string, vector<string>> m;
    
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    
    for(auto r : report){
        stringstream ss(r);
        string s;
        vector<string> v;
        
        while(ss >> s) v.push_back(s);
        m[v[0]].push_back(v[1]);
        check[v[1]]++;
    }
    
    for(auto i : id_list){
        int cnt = 0;
        for(auto v : m[i])
            if(check[v] >= k)
                cnt++;
        answer.push_back(cnt);
    }
    
    return answer;
}