#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<long long>> combi;
vector<int> col_one;

void calc_comb(int row){
    combi[0][0] = 1;
    for(int i = 1;i <= row;i++){
        for(int j = 0;j <= row;j++){
            if(j == 0) combi[i][j] = 1;
            else if(i == j) combi[i][j] = 1;
            else combi[i][j] = combi[i - 1][j - 1] + combi[i - 1][j];
            
            combi[i][j] %= 10000019;
        }
    }
}

void calc_one(vector<vector<int>> &map){
    for(int i = 0;i < map.size();i++){
        for(int j = 0;j <map[0].size();j++){
            col_one[j] += map[i][j];
        }
    }
}

int solution(vector<vector<int>> a) {
    int row = a.size(), col = a[0].size();
    combi.resize(row + 1, vector<long long>(row + 1, 0));
    calc_comb(row);
    
    col_one.resize(col + 1, 0);
    calc_one(a);
    
    vector<vector<long long>> dp(col + 2, vector<long long>(row + 1, 0));
    
    dp[1][row - col_one[0]] = combi[row][row - col_one[0]];

    for(int c = 1;c < col;c++){
        int one = col_one[c];
        for(int even = 0;even <= row;even++){
            if(dp[c][even] == 0) continue;
            for(int k = 0;k <= one;k++){
                if(even < k) continue;
                int even_row = even + one - (2 * k);
                if(even_row > row) continue;
                
                long long result = (combi[even][k] * combi[row - even][one - k]) % 10000019;
                dp[c + 1][even_row] += (dp[c][even] * result);
                dp[c + 1][even_row] %= 10000019;
            }
        }
    }
    return dp[col][row];  
}