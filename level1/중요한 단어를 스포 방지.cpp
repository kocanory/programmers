#include <string>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    int i = 0, n = message.size();
    vector<tuple<string, int, int>> words;
    
    while(i < n){
        if(message[i] == ' '){
            i++;
            continue;
        }
        int start = i;
        string word = "";
        while(i < n && message[i] != ' '){
            word += message[i];
            i++;
        }
        words.push_back({word, start, i - 1});
    }
    
    vector<bool> covered(n);
    
    for(auto s : spoiler_ranges)
        for(int i = s[0];i <= s[1];i++)
            covered[i] = true;
    
    set<string> normal_words;
    for (auto [w, s, e] : words){
        bool flag = true;
        for(int i = s;i <= e;i++)
            if(covered[i]){
                flag = false;
                break;
            }
        if(flag) normal_words.insert(w);
    }
    
    set<string> used;
    for(auto [w, s, e] : words){
        bool flag = false;
        for(int i = s;i <= e;i++){
            if(covered[i]){
                flag = true;
                break;
            }
        }
        
        if(flag){
            if(normal_words.find(w) == normal_words.end() && used.find(w) == used.end()){
                answer++;
                used.insert(w);
            }
        }
    }
    return answer;
}