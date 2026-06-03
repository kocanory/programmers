#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s.size() % 2 ? s.substr(s.size() / 2, 1) : s.substr(s.size() / 2 - 1, 2);
    return answer;
}