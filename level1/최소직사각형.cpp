#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int h = 0, w = 0;
    
    for(auto s : sizes){
        int a = s[0], b = s[1];
        if(a < b) swap(a, b);
        h = max(h, a);
        w = max(w, b);
    }
    return h * w;
}