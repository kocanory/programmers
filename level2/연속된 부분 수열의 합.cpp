#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = sequence.size() - 1;
    int left = 0, right = 1, sum = sequence[left];
    
    while(left < right)
    {
        if(sum == k)
        {
            if(right - 1 - left < answer[1] - answer[0])
            {
                answer[0] = left;
                answer[1] = right - 1;
            }
            sum -= sequence[left++];
        }
        else if(sum > k)
        {
            sum -= sequence[left++];      
        }
        else if(right < sequence.size())
        {
            sum += sequence[right++];
        }
        else{
            break;
        }
    }
    return answer;
}