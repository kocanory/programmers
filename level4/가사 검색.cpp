#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Trie{
    map<char, Trie *> child;
    bool end;
    int count;
    Trie(){
        end = false;
        count = 0;
    }
    
    void insert(string str){
        Trie * now = this;
        for(auto s : str)
        {
            if(now -> child[s] == NULL) now -> child[s] = new Trie();
            now -> count++;
            now = now -> child[s];
        }
        now -> count++;
        now -> end = true;
    }
    
    int find(string query)
    {
        Trie * now = this;
        for(auto q : query)
        {
            if(q == '?') return now -> count;
            if(now -> child[q] == NULL) return 0;
            now = now -> child[q];
        }
        return 0;
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<Trie> ascend(10001);
    vector<Trie> descend(10001);
    
    for(auto w : words)
    {
        ascend[w.length()].insert(w);
        reverse(w.begin(), w.end());
        descend[w.length()].insert(w);
    }
    
    for(auto q : queries)
    {
        if (q[0] != '?')
            answer.push_back(ascend[q.length()].find(q));
        else{
            reverse(q.begin(), q.end());
            answer.push_back(descend[q.length()].find(q));
        }        
    }
    return answer;
}