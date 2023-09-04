#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for(int i = citations.back();i>= 0;i--)
    {
        int count = 0;
        for(auto a : citations)
        {
            if(a >= i)
                count++;
        }
        if(count >= i)
        {
            answer = i;
            break;
        }
    }
    return answer;
}