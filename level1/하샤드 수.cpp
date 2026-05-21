#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int num = 0;
    
    for(auto a : to_string(x))
        num += (a - '0');
    
    return x % num == 0;
}