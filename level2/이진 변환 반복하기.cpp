#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int count = 0, erased = 0;
    for(int i = 0;i<s.length();i++)
    {
        while(s[i] == '0'){
            erased++;
            s.erase(i, 1);
        }
    }
    
    while(s != "1")
    {        
        int size = s.length();
        s.clear();
        while(size != 0)
        {
            if(size % 2)
                s = to_string(size % 2) + s;
            else
                erased++;
            size /= 2;
        }
        count++;
    }
    answer.push_back(count + 1);
    answer.push_back(erased);
    return answer;
}