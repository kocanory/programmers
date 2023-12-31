#include <string>
#include <vector>
#include <cmath>

using namespace std;

void check(vector<int> &answer, int i, string s)
{
    if(answer[i] && (s.length() / 2))
    {
        int l = s.length() / 2;
        if(s[l] == '0' && (s.find("1") != string::npos))
            answer[i] = 0;
        else
        {
            check(answer, i, s.substr(0, l));
            check(answer, i, s.substr(s.length() - l));
        }
    }
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer(numbers.size(), 1);
    int i = 0;
    for(auto num : numbers)
    {
        string n = "";
        while(num > 0)
        {
            n  = to_string(num % 2) + n;
            num /= 2;
        }
        int exp = 0;
        while(pow(2, exp) <= n.length()) exp++;
        while(n.length() < pow(2, exp) - 1) n = '0' + n;
        check(answer, i, n);
        i++;
    }
    return answer;
}