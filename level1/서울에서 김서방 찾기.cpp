#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    int idx = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
    return "김서방은 " + to_string(idx) + "에 있다";
}