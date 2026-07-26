#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> rank;
    
    for(int i = 0;i < players.size();i++)
        rank[players[i]] = i;
        
    for(auto c : callings){
        int idx = rank[c];
        rank[c] -= 1;
        rank[players[idx - 1]] += 1;
        swap(players[idx], players[idx - 1]);
    }
    return players;
}