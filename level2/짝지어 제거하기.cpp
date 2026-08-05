#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
    vector<char> arr;
    
    for(auto a : s){
        if(!arr.empty() && arr.back() == a)
            arr.pop_back();
        else
            arr.push_back(a);
    }

    return arr.empty();
}