#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    vector<int> dp1(size, 0);
    vector<int> dp2(size, 0);
    
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i = 2;i < size - 1;i++)
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
    
    for(int i = 2;i < size;i++)
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    
    int max1 = *max_element(dp1.begin(), dp1.end());
    int max2 = *max_element(dp2.begin(), dp2.end());
    return answer = max(max1, max2);
}