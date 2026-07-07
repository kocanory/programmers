#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end(), greater<>());
    
    for(int i = 0;i < score.size() / m;i++)
        answer += m * score[i * m + m - 1];
    return answer;
}