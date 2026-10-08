#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int c;

bool cmp(vector<int> a, vector<int> b){
    if(a[c - 1] == b[c - 1]) return a[0] > b[0];
    return a[c - 1] < b[c - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = -1;
    c = col;
    sort(data.begin(), data.end(), cmp);
    
    for(int i = row_begin - 1, val;i < row_end;i++){
        val = 0;
        for(auto d : data[i])
            val += (d % (i + 1));
        
        if(answer == -1) answer = val;
        else answer ^= val;
    }
    
    return answer;
}