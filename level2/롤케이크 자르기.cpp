#include <map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    
    for(auto t : topping) m1[t]++;
    
    for(auto t : topping){
        m1[t]--;
        m2[t]++;
        
        if(!m1[t]) m1.erase(t);
        if(m1.size() == m2.size()) answer++;
    }
    
    return answer;
}