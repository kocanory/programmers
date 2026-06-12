#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer = {gcd(n, m), n * m / gcd(n, m)};
    return answer;
}