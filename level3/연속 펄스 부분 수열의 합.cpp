#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int size = sequence.size();
    vector<long long> dpPos(size);
    vector<long long> dpNeg(size);
    
    for(int i = 0;i<size;i++)
        if(i % 2 == 0)
            sequence[i] = -1 * sequence[i];
    
    dpPos[0] = sequence[0];
    dpNeg[0] = sequence[0];
    answer = abs(sequence[0]);
    for(int i = 1;i<size;i++)
    {
        dpPos[i] = max(dpPos[i - 1] + sequence[i], (long long)sequence[i]);
        dpNeg[i] = min(dpNeg[i - 1] + sequence[i], (long long)sequence[i]);
        answer = max(answer, (long long)max((long long)abs(dpPos[i]), (long long)abs(dpNeg[i])));
    }
    return answer;
}