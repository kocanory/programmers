#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> blocks(201, vector<int>(6, -1));
    vector<vector<int>> makeblocks;
    int n = board.size();
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(board[i][j] > 0){
                int b = board[i][j];
                blocks[b][0] = b;
                
                blocks[b][1] = blocks[b][1] == -1 ? i : blocks[b][1] > i ? i : blocks[b][1];
                blocks[b][3] = blocks[b][3] == -1 ? i : blocks[b][3] < i ? i : blocks[b][3];
                blocks[b][2] = blocks[b][2] == -1 ? j : blocks[b][2] > j ? j : blocks[b][2];
                blocks[b][4] = blocks[b][4] == -1 ? j : blocks[b][4] < j ? j : blocks[b][4];
            }
        }
    }
    
    for(int i = 0 ;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(board[i][j] > 0)
            {
                int b = board[i][j];
                if(blocks[b][5] == -1)
                {
                    blocks[b][5] = 1;
                    makeblocks.push_back(blocks[b]);
                }
            }
        }
    }

    for(int k = 0;k < makeblocks.size();k++){
        vector<int> b = makeblocks[k];
        if(b[0] == 0) continue;
        int count = 0;
        
        for(int i = b[1];i <= b[3];i++)
        {
            for(int j = b[2];j <= b[4];j++)
            {
                if(i < b[3] && board[i][j] == 0)
                {
                    bool isEmpty = true;
                    for(int l = 0;l <= i;l++)
                    {
                        if(board[l][j] != 0)
                        {
                            isEmpty = false;
                            break;
                        }
                    }
                    if(isEmpty) count++;
                }
            }
        }
        if(count == 2){
            answer++;
            for(int i = b[1];i <= b[3];i++)
                for(int j = b[2];j <= b[4];j++)
                    board[i][j] = 0;
            makeblocks[k][0] = 0;
            if(k > 0) k -= 2;
        }
    }
    return answer;
}