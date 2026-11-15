#include <string>
#include <vector>

using namespace std;

int conv(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int calcCount(int t){
    int hCnt = t * 719 / 43200, mCnt = t * 59 / 3600;
    return hCnt + mCnt - (t >= 43200 ? 2 : 1);
}

int check(int t){
    return t * 719 % 43200 == 0 || t * 59 % 3600 == 0;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = calcCount(conv(h2, m2, s2)) - calcCount(conv(h1, m1, s1)) + check(conv(h1, m1, s1));
    return answer;
}