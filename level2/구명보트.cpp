#include <string>
#include <vector>

using namespace std;
int w[241] = {0, };

int solution(vector<int> people, int limit) {
    int answer = 0;
    for(auto a : people)
        w[a]++;
    
    for(auto a : people)
    {
        if(w[a] > 0)
        {
            w[a]--;
            for(int i = limit - a;i > 39;i--)
            {
                if(w[i] > 0)
                {
                    w[i]--;
                    break;
                }
            }
            answer++;
        }
    }
    return answer;
}