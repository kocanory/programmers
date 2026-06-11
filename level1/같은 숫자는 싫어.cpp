#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(auto a : arr){
        if(answer.empty() || answer.back() != a)
            answer.push_back(a);
    }

    return answer;
}