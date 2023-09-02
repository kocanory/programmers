#include <string>
#include <vector>
#include <map>
using namespace std;

int cloth[4] = {0, };

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(auto a : clothes)
        m[a[1]]++;
    for(auto a : m)
        answer *= (a.second + 1);
    answer -= 1;
    return answer;
}