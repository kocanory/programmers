#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> top(board[0].size()), stack;
    
    for(int j = 0;j < board[0].size();j++)
        for(int i = 0;i < board.size();i++)
            if(board[i][j]){
                top[j] = i;
                break;
            }
    
    for(auto m : moves){
        if(top[m - 1] == board.size()) continue;
        int val = board[top[m - 1]][m - 1];
        top[m - 1]++;
        if(!stack.empty() && stack.back() == val){
            answer += 2;
            stack.pop_back();
        }
        else stack.push_back(val);
    }
    return answer;
}