#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int arr[] = {1, 2, 4};
    string num = "";
    while(n > 0)
    {
        n--;
        num = to_string(n % 3) + num;
        n /= 3;
    }
    for(auto a : num)
    {
        answer += to_string(arr[a - '0']);
    }
    return answer;
}