#include <string>
#include <vector>

using namespace std;

void recursive(int &count, bool &flag, string word, string rec, string alpha)
{
    
    if(word == rec)
    {
        flag = true;
        return;        
    }
    if(rec.length() >= 5) return;
    
    for(int i = 0;i<5;i++)
    {
        count++;
        rec += alpha[i];        
        recursive(count, flag, word, rec, alpha);
        if(flag) return;
        rec.pop_back();
    }
}

int solution(string word) {
    int answer = 0, count = 0;
    bool flag = false;
    string alpha = "AEIOU";
    recursive(count, flag, word, "", alpha);
    return answer = count;
}