#include <string>
#include <vector>

using namespace std;

int convert(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

int countAlarm(int time){
    int h_alarm = time * 719 / 43200;
    int m_alarm = time * 59 / 3600;
    int penalty = 43200 <= time ? 2 : 1;
    return h_alarm + m_alarm - penalty;
}

bool alarmNow(int time){
    return time * 719 % 43200 == 0 || time * 59 % 3600 == 0;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int t1 = convert(h1, m1, s1), t2 = convert(h2, m2, s2);
    return countAlarm(t2) - countAlarm(t1) + (alarmNow(t1) ? 1 : 0);
}