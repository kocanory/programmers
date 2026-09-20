#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long s1 = 0, s2 = 0, cnt = 0;
    queue<long long> q1, q2;
    
    for(int i = 0;i < queue1.size();i++){
        s1 += queue1[i];
        s2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    while(true){
        if(cnt > queue1.size() * 4) return - 1;
        
        long long val;
        if(s1 > s2){
            val = q1.front(); q1.pop();
            s1 -= val;
            s2 += val;
            q2.push(val);
        }
        else if(s1 < s2){
            val = q2.front(); q2.pop();
            s2 -= val;
            s1 += val;
            q1.push(val);
        }
        else return cnt;
        cnt++;
    }
}