#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    
    for(int i = 0, sum;i < elements.size();i++){
        sum = 0;
        for(int j = 0;j < elements.size();j++){
            sum += elements[(i + j) % elements.size()];
            s.insert(sum);
        }
    }
    
    return s.size();
}