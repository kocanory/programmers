#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, string> m = {{"C#", "c"}, {"D#", "d"}, {"F#", "f"}, {"G#", "g"}, {"A#", "a"}};

int conv(string t){
    stringstream ss(t);
    string s;
    int res = 0, mul = 60;
    while(getline(ss, s, ':')){
        res += stoi(s) * mul;
        mul /= 60;
    }
    return res;
}

string change(string x){
    
    string res = "";
    for(int i = 0;i < x.size();i++){
        if(x[i + 1] == '#'){
            res += m[x.substr(i, 2)];
            i++;
        }
        else
            res += x[i];
    }
    return res;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    m = change(m);
    int maxL = 0;
    
    for(auto mu : musicinfos){
        stringstream ss(mu);
        string s;
        vector<string> vec;
        
        while(getline(ss, s, ','))
            vec.push_back(s);
        
        
        int l = conv(vec[1]) - conv(vec[0]);
        if(maxL >= l) continue;
        
        s = "";
        for(int i = 0, idx = 0;i < l;i++){
            s += vec[3][idx];
            idx = (idx + 1) % vec[3].size();
            if(vec[3][idx] == '#'){
                s += vec[3][idx];
                idx = (idx + 1) % vec[3].size();
            }
        }
        
        s = change(s);

        if (s.find(m) != string::npos){
            if(maxL < l){
                maxL = l;
                answer = vec[2];
            }
        }
        
    }
    
    return (answer.empty() ? "(None)" : answer);
}