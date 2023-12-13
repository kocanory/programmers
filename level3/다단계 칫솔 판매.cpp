#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> parent;
map<string, int> benefit;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i = 0;i < enroll.size();i++)
    {
        parent[enroll[i]] = referral[i];
    }
    
    for(int i = 0;i < amount.size();i++)
    {
        string now = seller[i];
        int price = amount[i] * 100;
        while(now != "-")
        {
            if(price / 10 == 0)
            {
                benefit[now] += price;
                break;
            }
            benefit[now] += (int)(price - price / 10);
            price /= 10;
            now = parent[now];
        }
    }
    
    for(auto e : enroll)
        answer.push_back(benefit[e]);
    return answer;
}