#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1;i < food.size();i++)
        answer += string(food[i] / 2, i + '0');
    
    string rev = answer;
    reverse(rev.begin(), rev.end());
    
    return answer + "0" + rev;
}