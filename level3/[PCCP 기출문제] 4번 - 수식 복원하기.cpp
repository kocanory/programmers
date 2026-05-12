#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

int conv(int d, string n){
    int res = 0;
    for(int i = 0;i < n.size();i++)
        res += pow(d, i) * (n[n.size() - 1 - i] - '0');
    return res;
}

string reco(int d, int n){
    if(n == 0) return "0";
    string res = "";
    while(n){
        res = char(n % d + '0') + res;
        n /= d;
    }
    return res;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<vector<string>> o, x;
    
    int max_d = 2;
    
    for(auto e : expressions){
        stringstream ss(e);
        string s;
        vector<string> tmp;
        while(getline(ss, s, ' '))
            tmp.push_back(s);
        
        if(tmp.back() == "X") x.push_back(tmp);
        else o.push_back(tmp);
        
        for(int i = 0;i < tmp.size();i += 2){
            if(tmp[i] == "X") continue;
            for(int j = 0;j < tmp[i].size();j++)
                max_d = max(max_d, (tmp[i][j] - '0') + 1);
        }
    }
    
    vector<int> pd;

    for(int i = max_d;i <= 9;i++){
        bool flag = true;
        for(auto a : o){
            if ((a[1] == "+" && (conv(i, a[0]) + conv(i, a[2]) != conv(i, a[4]))) || (a[1] == "-" && (conv(i, a[0]) - conv(i, a[2]) != conv(i, a[4])))){
                flag = false;
                break;
            }
        }
        if(flag) pd.push_back(i);
    }
    
    for(auto &a : x){
        set<string> check;
        for(auto b : pd){
            if(a[1] == "+")
                check.insert(reco(b, conv(b, a[0]) + conv(b, a[2])));
            else
                check.insert(reco(b, conv(b, a[0]) - conv(b, a[2])));
        }
        
    
        if(check.size() == 1)
            a[4] = *check.begin();
        else
            a[4] = "?";
    
        string res = "";
        
        for(int i = 0;i < a.size();i++){
            res += a[i];
            if (i < a.size() - 1)
                res += " ";
        }
        
        answer.push_back(res);
        
    }
    
    
    return answer;
}