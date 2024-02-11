#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = -1;
    vector<int> left(cookie.size() + 1, 0);
    vector<int> right(cookie.size() + 1, 0);
    
    for(int i = 1;i <= cookie.size();i++)
    {
        left[i] = left[i - 1] + cookie[i - 1];
        right[cookie.size() - i] = right[cookie.size() - i + 1] + cookie[cookie.size() - i];
    }
    
    for(int i = 1;i <= cookie.size();i++)
    {
        int leftVal = left[i], rightVal = right[i];
        int leftCur = 0, rightCur = cookie.size();
        while(true)
        {
            if(leftCur > i || rightCur < i) break;
            int l = leftVal - left[leftCur];
            int r = rightVal - right[rightCur];
            
            if(l == r)
            {
                answer = max(answer, r);
                break;
            }
            if(l > r) leftCur++;
            else rightCur--;
        }
    }
    return answer;
}