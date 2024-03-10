#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    unordered_map<int, int> root;
    for(auto e : edges)
        root[e[0]]++;
    
    for(auto e : edges){
        if(root.find(e[1]) != root.end()) root.erase(e[1]);
    }
    
    int center_count = -1;
    for(auto r : root){
        if(r.second > center_count){
            answer[0] = r.first;
            center_count = r.second;
        }
    }
    
    vector<int> starts;
    unordered_map<int, int> node;
    
    for(auto e : edges){
        if(e[0] == answer[0]) starts.push_back(e[1]);
        else{
            if(node.find(e[0]) == node.end()){
                node[e[0]] = e[1];
            }
            else{
                node.erase(e[0]);
                answer[3]++;
            }
        }
    }
    
    for(auto s : starts){
        if(node.find(s) == node.end()) continue;
        int next = s;
        while(true){
            if(node.find(next) != node.end()){
                next = node[next];
                if(next == s){
                    answer[1]++;
                    break;
                }
            }
            else break;
        }
    }
    
    answer[2] = starts.size() - answer[1] - answer[3];
    return answer;
}