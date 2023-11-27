#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    if(sticker.size() == 1)
        return sticker[0];
    
    vector<int> dp1(sticker.size(), 0);
    vector<int> dp2(sticker.size(), 0);
    
    for(int i = 0;i < dp1.size() - 1;i++)
    {
        if(i == 0)
            dp1[i] = sticker[0];
        else if(i == 1)
            dp1[i] = max(sticker[0], sticker[1]);
        else
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + sticker[i]);
    }
    
    for(int i = 0;i < dp2.size();i++)
    {
        if(i == 0)
            dp2[i] = 0;
        else if(i == 1)
            dp2[i] = sticker[1];
        else
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }

    return answer = max(dp1[sticker.size() - 2], dp2[sticker.size() - 1]);
}