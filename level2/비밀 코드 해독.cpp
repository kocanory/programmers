#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;

bool check(vector<vector<int>> q, vector<int> ans, vector<int> num){
    for(int i = 0;i < q.size();i++){
        int cnt = 0;
        for(int n : num){
            if(find(q[i].begin(), q[i].end(), n) != q[i].end())
                cnt++;
        }
        if (cnt != ans[i])
            return false;
    }
    return true;
}

void find(int n, vector<vector<int>> q, vector<int> ans, int now, vector<int> num){
    if(num.size() == 5){
        if(check(q, ans, num))
            answer++;
        return;
    }
    for(int i = now;i <= n;i++){
        num.push_back(i);
        find(n, q, ans, i + 1, num);
        num.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    find(n, q, ans, 1, vector<int>());
    return answer;
}