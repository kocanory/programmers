#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4), starts;
    unordered_map<int, int> check, node;
    
    for(auto e : edges)
        check[e[0]]++;
    
    for(auto e : edges){
        if(check.find(e[1]) != check.end())
            check.erase(e[1]);
    }
    
    int maxCnt = -1;
    for(auto [k, v] : check){
        if(v > maxCnt){
            answer[0] = k;
            maxCnt = v;
        }
    }
    
    for(auto e : edges){
        if(e[0] == answer[0]) starts.push_back(e[1]);
        else{
            if(node.find(e[0]) == node.end())
                node[e[0]] = e[1];
            else{
                node.erase(e[0]);
                answer[3]++;
            }
        }
    }
    
    for(auto s : starts){
        if(node.find(s) == node.end()) continue;
        int now = s;
        while(true){
            if(node.find(now) != node.end()){
                now = node[now];
                if(now == s){
                    answer[1]++;
                    break;
                }
            }
            else break;
        }
    }
    
    answer[2] = starts.size() - (answer[1] + answer[3]);
    return answer;
}