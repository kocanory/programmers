#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> check;
    
    for(auto p : phone_book) check[p]++;
    
    for(auto p : phone_book){
        string word = "";
        for(int i = 0;i < p.size() - 1;i++){
            word += p[i];
            if(check[word])
                return false;
        }
    }
    
    return true;
}