#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(auto num : s)
    {
        int oneCount = 0, ooz = 0;
        string r = "";
        for(auto n : num)
        {
            if(n == '1')
                oneCount++;
            else
            {
                if(oneCount >= 2)
                {
                    ooz++;
                    oneCount -= 2;
                }
                else
                {
                    while(oneCount--) r += '1';
                    r += '0';
                    oneCount = 0;
                }
            }
        }
        while(ooz--) r += "110";
        while(oneCount--) r += '1';
        answer.push_back(r);
    }
    return answer;
}