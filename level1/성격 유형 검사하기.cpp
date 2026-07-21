#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> check;
    
    for(int i = 0, val;i < survey.size();i++){
        val = abs(4 - choices[i]);
        if(!val) continue;
        if(choices[i] > 4) check[survey[i][1]] += val;
        else check[survey[i][0]] += val;
    }
    
    answer += (check['R'] >= check['T'] ? 'R' : 'T');
    answer += (check['C'] >= check['F'] ? 'C' : 'F');
    answer += (check['J'] >= check['M'] ? 'J' : 'M');
    answer += (check['A'] >= check['N'] ? 'A' : 'N');
    
    return answer;
}