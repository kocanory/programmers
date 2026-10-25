using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    double a = -h / (double)w;
    
    for(int i = 1;i <= w;i++)
        answer += (int)(a * i + h) * 2;
    return answer;
}