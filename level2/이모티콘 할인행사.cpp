#include <string>
#include <vector>

using namespace std;

void recursive(vector<int> &answer, vector<vector<int>> &users, vector<int> &emoticons, vector<int> discount)
{
    if(discount.size() == emoticons.size())
    {
        int price = 0, subscribe = 0;
        for(auto u : users)
        {
            int sum = 0;
            for(int i = 0;i<emoticons.size();i++)
            {
                if(discount[i] >= u[0])
                    sum += (emoticons[i] / 100 * (100 - discount[i])); 
            }
            if(sum >= u[1]) subscribe++;
            else price += sum;
        }
        if((answer[0] == subscribe) && (answer[1] < price))
            answer[1] = price;
        else if(answer[0] < subscribe)
        {
            answer[0] = subscribe;
            answer[1] = price;
        }
        return;
    }
    
    for(int d = 40; d >= 10; d -= 10)
    {
        discount.push_back(d);
        recursive(answer, users, emoticons, discount);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    vector<int> discount;
    recursive(answer, users, emoticons, discount);
    return answer;
}