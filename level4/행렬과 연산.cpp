#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int r = rc.size();
    int c = rc[0].size();
    deque<int> first, last;
    deque<int> rows[r];
    for(int i = 0;i < r;i++)
    {
        first.push_back(rc[i][0]);
        last.push_back(rc[i][c - 1]);
    }
    
    for(int i = 0;i < r;i++)
    {
        for(int j = 1;j < c - 1;j++)
            rows[i].push_back(rc[i][j]);
    }
    
    int idx = 0;
    
    for(auto o : operations)
    {
        if(o == "ShiftRow")
        {
            first.push_front(first.back());
            first.pop_back();
            last.push_front(last.back());
            last.pop_back();
            idx = ((idx - 1) + r) % r;
        }
        else
        {
            rows[idx].push_front(first.front());
            first.pop_front();
            last.push_front(rows[idx].back());
            rows[idx].pop_back();
            
            rows[(idx - 1 + r) % r].push_back(last.back());
            last.pop_back();
            first.push_back(rows[(idx - 1 + r) % r].front());
            rows[(idx - 1 + r) % r].pop_front();
        }
    }
    
    for(int i = 0;i < r;i++)
    {
        rc[i][0] = first[i];
        for(int j = 1;j < c - 1;j++)
            rc[i][j] = rows[(i + idx) % r][j - 1];
        rc[i][c - 1] = last[i];
    }
    
    return rc;
}