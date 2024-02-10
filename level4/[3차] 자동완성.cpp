#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int answer = 0;

struct Trie{
    unordered_map<char, Trie*> child;
    int count;
    bool end;
    
    Trie(){
        count = 0;
        end = false;
    }
    
    void insert(string &str)
    {
        Trie *now = this;
        for(auto &s : str)
        {
            
            if(now->child[s] == NULL) 
                now->child[s] = new Trie();
            now = now->child[s];
            now->count++;
        }
        now->end = true;
    }
    
    void find(string &str)
    {
        Trie *now = this;
        int cnt = 0;
        for(auto &s : str)
        {  
            now = now -> child[s];
            cnt++;
            if(now->count <= 1){
                break;
            }
        }
        answer += cnt;
    }
};

int solution(vector<string> words) {
    Trie *root = new Trie();
    for(auto &w : words)
        root -> insert(w);
    
    for(auto &w : words)
        root -> find(w);
    return answer;
}