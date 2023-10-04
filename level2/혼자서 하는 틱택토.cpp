#include <string>
#include <vector>

using namespace std;

int count[2] = {0, 0};

void getCount(vector<string> board)
{
    for(auto i : board)
    {
        for(auto j : i)
        {
            if(j == 'O') count[0]++;
            else if(j == 'X') count[1]++;
        }
    }
}

int solution(vector<string> board) {
    getCount(board);
    
    bool o = false;
    bool x = false;
    
    for(int i = 0;i<board.size();i++)
    {
        string s = board[i];
        
        if(s == "OOO") o = true;
        else if(s == "XXX") x = true;
        
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == 'O') o = true;
            else if(board[0][i] == 'X') x = true;
        }
    }
    
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        if(board[1][1] == 'O') o = true;
        else if(board[1][1] == 'X') x = true;
    }
    
    if(count[0] == count[1])
    {
        if((!o && !x) || (x && !o)) return 1;
    }
    if(count[0] == count[1] + 1)
    {
        if((!o && !x) || (o && !x)) return 1;
    }
    
    return 0;
}