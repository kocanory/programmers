#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> detach(string word)
{
    vector<string> temp;
    for(int i = 0;i<word.length();i++)
    {
        if(word[i] >= '0' && word[i] <= '9')
        {
            temp.push_back(word.substr(0, i));
            word.erase(0, i);
            break;
        }
        else
            word[i] = tolower(word[i]);
    }
    
    for(int i = 0;i<word.length();i++)
    {
        if(!(word[i] >= '0' && word[i] <= '9'))
        {
            temp.push_back(word.substr(0, i));
            word.erase(0, i);
            break;
        }
    }
    temp.push_back(word);
    return temp;
}

bool comp(string a, string b)
{
    vector<string> a_detach = detach(a);
    vector<string> b_detach = detach(b);
    
    if(a_detach[0] == b_detach[0]) return stoi(a_detach[1]) < stoi(b_detach[1]);
    return a_detach[0] < b_detach[0];
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    stable_sort(files.begin(), files.end(), comp);
    return answer = files;
}