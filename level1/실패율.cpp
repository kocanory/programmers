#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer, check(N + 1);
    vector<pair<int, double>> arr;
    
    int human = stages.size();
    
    for(auto s : stages) check[s]++;
    
    for(int i = 1;i <= N;i++){
        if(!human) arr.push_back({i, 0});
        else{
            arr.push_back({i, check[i] / (double)human});
            human -= check[i];
        }
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    for(auto [k, v] : arr)
        answer.push_back(k);
    
    return answer;
}