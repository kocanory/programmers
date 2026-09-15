#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> conv(string f){
    int idx = 0;
    string tmp = "";
    vector<string> v;
    
    while(idx < f.size() && !isdigit(f[idx])){
        tmp += tolower(f[idx]);
        idx++;
    }
    
    v.push_back(tmp);
    tmp.clear();
        
    while(idx < f.size() && isdigit(f[idx])){
        tmp += f[idx];
        idx++;
    }
    
    v.push_back(tmp);
    v.push_back(f.substr(idx, f.size() - idx));
    return v;
}

bool comp(string a, string b){
    vector<string> va = conv(a), vb = conv(b);
    if(va[0] == vb[0]) return stoi(va[1]) < stoi(vb[1]);
    return va[0] < vb[0];
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), comp);
    return files;
}