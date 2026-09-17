#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        bool flag = false;
        vector<vector<bool>> check(m, vector(n, false));
        
        for(int i = 0;i < m - 1;i++){
            for(int j = 0;j < n - 1;j++){
                if(board[i][j] == '0') continue;
                if(board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]){
                    flag = true;
                    check[i][j] = true;
                    check[i][j + 1] = true;
                    check[i + 1][j] = true;
                    check[i + 1][j + 1] = true;
                }
            }
        }
        
        if(!flag) break;
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(check[i][j]){
                    answer++;
                    board[i][j] = '0';
                }
            }
        }
        
        for(int j = 0;j < n;j++){
            string tmp = "";
            for(int i = 0;i < m;i++)
                if(board[i][j] != '0') tmp += board[i][j];
            tmp = string(m - tmp.size(), '0') + tmp;
            
            for(int i = 0;i < m;i++)
                board[i][j] = tmp[i];
        }
    }
    
    return answer;
}