#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string word = "";
    int count = 0;
    while(word.length() <= t * m)
    {        
        int number = count;
        string str = "";
        if(number == 0)
        {
            str += '0';
        }
        else
        {
            while(number > 0)
            {
                if(number % n < 10)
                    str = to_string(number % n) + str;
                else
                    str = (char)('A' + (number % n) - 10) + str;         
                number /= n;
            }
        }
        word += str;
        count++;
    }
    
    for(int i = p - 1;answer.length() < t;i += m)
        answer += word[i];
    return answer;
}