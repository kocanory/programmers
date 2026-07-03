#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int days = 0;
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i = 1;i < a;i++) days += month[i];
    days += b - 1;
    return day[days % 7];
}