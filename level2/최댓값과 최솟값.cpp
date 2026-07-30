#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    int Max = -1e9, Min = 1e9;
    
    stringstream ss(s);
    string tmp;
    
    while(ss >> tmp){
        Max = max(stoi(tmp), Max);
        Min = min(stoi(tmp), Min);
    }
    
    return answer = to_string(Min) + " " + to_string(Max);
}