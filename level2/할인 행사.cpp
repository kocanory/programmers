#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i = 0;i<discount.size() - 9;i++)
    {
        int j = 0;
        for(j = 0;j < want.size();j++)
        {
            int check = 0;
            for(int k = i;k< i + 10;k++)
            {
                if(discount[k] == want[j]) check++;
            }
            if(check < number[j]) break;
        }
        if(j == want.size()) answer++;
    }
    return answer;
}