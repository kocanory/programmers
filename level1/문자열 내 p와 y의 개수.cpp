#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p_cnt = 0, y_cnt = 0;
    
    for(auto a : s){
        a = tolower(a);
        if(a == 'p') p_cnt++;
        if(a == 'y') y_cnt++;
    }
    
    return p_cnt == y_cnt;
}