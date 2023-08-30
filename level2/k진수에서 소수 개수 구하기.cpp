#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    while(n > 0)
    {
        num = to_string(n % k) + num;
        n /= k;
    }
    
    stringstream ss(num);
    string temp = "";
    while(getline(ss, temp, '0'))
    {
        if(temp != "")
        {
            long number = stol(temp);
            bool flag = true;
            for(int i = 2;i<=sqrt(number);i++)
                if(number % i == 0)
                {
                    flag = false;
                    break;
                }
            if(number != 1 && flag) answer++;
        }
    }
    
    return answer;
}