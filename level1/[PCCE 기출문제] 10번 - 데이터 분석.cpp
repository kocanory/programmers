#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> m;
string word;

bool comp(vector<int> a, vector<int> b){
    return a[m[word]] < b[m[word]];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    m["code"] = 0;
    m["date"] = 1;
    m["maximum"] = 2;
    m["remain"] = 3;
    word = ext;
    sort(data.begin(), data.end(), comp);
    
    for(auto d : data){
        if(d[m[word]] < val_ext) answer.push_back(d);
        else break;
    }
    
    word = sort_by;
    sort(answer.begin(), answer.end(), comp);
    return answer;
}