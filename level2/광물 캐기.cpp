#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    auto [d1, i1, s1] = a;
    auto [d2, i2, s2] = b;
    
    if(d1 == d2 && i1 == i2) return s1 > s2;
    if(d1 == d2) return i1 > i2;
    return d1 > d2;
}

vector<vector<int>> cost = {{1, 1, 1}, {5, 1, 1}, {25, 5, 1}};
map<string, int> conv = {{"diamond", 0}, {"iron", 1}, {"stone", 2}};
map<int, int> check;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0, sum = 0;
    vector<tuple<int, int, int>> arr;
    
    for(auto p : picks) sum += p;
    int size = min(sum * 5, (int)minerals.size());
    
    for(int i = 0;i < size;i++){
        if((i && i % 5 == 0)){
            arr.push_back({check[0], check[1], check[2]});
            check.clear();
        }
        check[conv[minerals[i]]]++;
    }
    
    arr.push_back({check[0], check[1], check[2]});
    sort(arr.begin(), arr.end(), cmp);
    
    int idx = 0;
    
    for(auto [d, i, s] : arr){
        while(!picks[idx])
            idx++;
        
        answer += cost[idx][0] * d + cost[idx][1] * i + cost[idx][2] * s;
        picks[idx]--;
    }
    
    return answer;
}