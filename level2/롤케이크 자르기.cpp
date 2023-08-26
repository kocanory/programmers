#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> m1, m2;
    for(auto a : topping)
        m1[a]++;
    
    for(auto a : topping)
    {
        m1[a]--;
        m2[a]++;
        if(m1[a] == 0) m1.erase(a);
        if(m1.size() == m2.size()) answer++;
    }
    return answer;
}