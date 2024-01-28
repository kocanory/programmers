#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0, check = cards.size() + 1;
    vector<int> getcard, keepcard;
    int index = 0;
    for(index;index < cards.size() / 3;index++)
        getcard.push_back(cards[index]);

    bool flag = true;
    while(index + 2 <= cards.size())
    {
        answer++;
        for(int i = 0;i < 2;i++)
            keepcard.push_back(cards[index++]);
        flag = false;
        if(getcard.size() >= 2)
        {
            for(int i = 0;i < getcard.size() && !flag;i++)
            {
                for(int j =i + 1;j <getcard.size();j++)
                {
                    if(getcard[i] + getcard[j] == check)
                    {
                        getcard.erase(getcard.begin() + j);
                        getcard.erase(getcard.begin() + i);
                        flag = true;
                        break;
                    }
                }
            }
        }

        if(getcard.size() >= 1 && keepcard.size() >= 1 && coin >= 1)
        {
            for(int i = 0;i < getcard.size() && !flag;i++)
            {
                for(int j = 0;j <keepcard.size();j++)
                {
                    if(getcard[i] + keepcard[j] == check)
                    {
                        keepcard.erase(keepcard.begin() + j);
                        getcard.erase(getcard.begin() + i);
                        flag = true;
                        coin--;
                        break;
                    }
                }
            }
        }

        
        if(keepcard.size() >= 2 && coin >= 2)
        {
            for(int i = 0;i < keepcard.size() && !flag;i++)
            {
                for(int j =i + 1;j <keepcard.size();j++)
                {
                    if(keepcard[i] + keepcard[j] == check)
                    {
                        keepcard.erase(keepcard.begin() + j);
                        keepcard.erase(keepcard.begin() + i);
                        flag = true;
                        coin -= 2;
                        break;
                    }
                }
            }
        }
        if(flag) continue;
        else break;
    }
    if(index >= cards.size() && flag) answer++;
    return answer;
}