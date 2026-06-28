#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    cards1.push_back("");
    cards2.push_back("");
    
    int idx1 = 0, idx2 = 0;
    
    for(auto g : goal){
        if(cards1[idx1] != g && cards2[idx2] != g){
            answer = "No";
            break;
        }
        else{
            if(cards1[idx1] == g) idx1++;
            else idx2++;
        }
    }
    
    return answer;
}