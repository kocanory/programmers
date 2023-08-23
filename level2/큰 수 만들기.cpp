#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    bool flag = true;
    while(flag)
    {
        for(int i = 1;i<number.length();i++)
        {
            if(number[i - 1] < number[i] && k > 0)
            {
                number.erase(i - 1, 1);
                k--;
                if(k == 0)
                    flag = false;
                break;
            }
            if(i == number.length() - 1)
                flag = false;
        }
    }
    while(k--)
        number.erase(number.length() - 1, 1);
    return answer = number;
}