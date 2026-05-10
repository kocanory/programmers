#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> answer;
    
    vector<int> rains(m * n + 1, (int)1e9);
    
    for(int i = 0;i < drops.size();i++){
        int r = drops[i][0], c = drops[i][1];
        rains[r * n + c] = i + 1;
    }
    
    int new_n = n - w + 1;
    vector<int> row_min(new_n * m);
    
    for(int i = 0;i < m;i++){
        deque<int> q;
        for(int j = 0;j < n;j++){
            while(!q.empty() && rains[i * n + q.back()] >= rains[i * n + j])
                q.pop_back();
            q.push_back(j);
            
            if(q.front() <= j - w)
                q.pop_front();
            if(j >= w - 1)
                row_min[i * new_n + (j - w + 1)] = rains[i * n + q.front()];
        }
    }
    
    int bt = -1, br = 0, bc = 0;
    
    for(int j = 0;j < new_n;j++){
        deque<int> q;
        for(int i = 0;i < m;i++){
            while(!q.empty() && row_min[new_n * q.back() + j] >= row_min[i * new_n + j])
                q.pop_back();
            
            q.push_back(i);
            
            if(q.front() <= i - h)
                q.pop_front();
            
            if(i >= h - 1){
                int now = row_min[new_n * q.front() + j], sr = i - h + 1;
                if(now > bt || (now == bt && (sr < br || (sr == br && j < bc)))){
                    bt = now;
                    br = sr;
                    bc = j;
                }
            }
        }
    }
    
    return answer = {br, bc};
}