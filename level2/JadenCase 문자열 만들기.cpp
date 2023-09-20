#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string temp = "";
    bool flag = false;
    while(getline(ss, temp, ' '))
    {
        if(flag) answer += " ";
        for(int i = 0;i<temp.length();i++)
        {
            if(i == 0 && islower(temp[i])) temp[i] = toupper(temp[i]);
            if(i != 0 && isupper(temp[i])) temp[i] = tolower(temp[i]);
        }
        if(!flag) flag = true;
        answer += temp;
    }
    if(s[s.length() - 1] == ' ') answer += " ";
    return answer;
}