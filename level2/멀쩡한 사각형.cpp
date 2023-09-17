using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double c = - h / (double)w;
    for(int i = 1;i < w;i++)
        answer += ((int)(c * i + h) * 2);
    return answer;
}