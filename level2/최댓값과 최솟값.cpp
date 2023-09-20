#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int>num;
    stringstream ss(s);
    string temp = "";
    while(getline(ss, temp, ' '))
    {
        num.push_back(stoi(temp));
    }
    sort(num.begin(), num.end());
    return answer = to_string(num.front()) + " " + to_string(num.back());
}