#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    string str_a = to_string(a), str_b = to_string(b);
    if(str_a[0] == str_b[0])
    {
        return stoi(str_a + str_b) > stoi(str_b + str_a);
    }
    return str_a[0]  > str_b[0];
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), comp);
    if(numbers[0] == 0) return "0";
    for(auto a : numbers)
        answer += to_string(a);
    return answer;
}