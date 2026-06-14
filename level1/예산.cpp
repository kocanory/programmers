#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int l = 0, val = 0;
    
    sort(d.begin(), d.end());
    for(int r = 0;r < d.size();r++){
        val += d[r];
        
        while(l < r){
            if(val <= budget)
                break;
            val -= d[l];
            l++;
        }
        
        if(val <= budget)
            answer = max(answer, r - l + 1);
    }
    return answer;
}