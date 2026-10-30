#include <string>
#include <vector>

using namespace std;

pair<int, int> check(vector<string> board){
    int oCnt = 0, xCnt = 0;
    
    for(auto b : board){
        for(auto a : b){
            if(a == 'O') oCnt++;
            else if(a == 'X') xCnt++;
        }
    }
    
    return {oCnt, xCnt};
}

int solve(vector<string> board){
    auto [oCnt, xCnt] = check(board);
    bool o = false, x = false;
    
    for(int i = 0;i < 3;i++){
        string row = board[i];
        if(row == "OOO") o = true;
        else if(row == "XXX") x = true;
        
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == 'O') o = true;
            else if(board[0][i] == 'X') x = true;
        }
    }
    
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[2][0] == board[1][1] && board[1][1] == board[0][2])){
        if(board[1][1] == 'O') o = true;
        else if(board[1][1] == 'X') x = true;
    }
    
    if(oCnt == xCnt)
        return (!o && !x) || (!o && x);
    if(oCnt == xCnt + 1)
        return (!o && !x) || (o && !x);
    
    return 0;
}

int solution(vector<string> board) {
    int answer = solve(board);
    return answer;
}