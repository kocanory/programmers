#include <string>
#include <vector>

using namespace std;

int process[101] = {0, };

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int back = 0;
    for(int i = 0;i<progresses.size();i++)
    {
        int remain = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i]) remain++;
        if(back > remain)
            remain = back;
        process[remain]++;
        back = remain;
    }
    for(int i = 0;i<=100;i++)
        if(process[i]) answer.push_back(process[i]);
    return answer;
}