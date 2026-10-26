#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> key;

bool cmp(string a, string b){
    if(a.size() == b.size()) return stoi(a) < stoi(b);
    return a.size() < b.size();
}

void makeKey(string now, int idx, int size){
    for(int i = idx;i < size;i++){
        string k = now + to_string(i);
        key.push_back(k);
        makeKey(k, i + 1, size);
    }
}

bool checkKey(string k, vector<vector<string>> &relation){
    for(int i = 0;i < relation.size();i++){
        string a = "";
        
        for(auto idx : k)
            a += relation[i][idx - '0'] + '_';
        
        for(int j = i + 1;j < relation.size();j++){
            string b = "";
            
            for(auto idx : k)
                b += relation[j][idx - '0'] + '_';
            
            if(a == b) return false;
        }
    }
    return true;
}

int findKey(vector<vector<string>> &relation){
    sort(key.begin(), key.end(), cmp);
    vector<bool> check(key.size(), true);
    int cnt = 0;
    
    for(int i = 0;i < key.size();i++){
        if(checkKey(key[i], relation) && check[i]){
            cnt++;
            
            for(int j = i + 1;j < key.size();j++){
                int same = 0;
                for(auto a : key[i]){
                    for(auto b : key[j]){
                        if(a == b){
                            same++;
                            break;
                        }
                    }
                }
                if(same == key[i].size())
                    check[j] = false;
            }
        }
    }
    return cnt;
}

int solution(vector<vector<string>> relation) {
    makeKey("", 0, relation[0].size());
    return findKey(relation);
}