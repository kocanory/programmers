#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    vector<string> spoke;
    for(int i = 0;i<words.size();i++)
    {
        if(find(spoke.begin(), spoke.end(), words[i]) == spoke.end() && ((i > 0 && words[i][0] == words[i - 1][words[i-1].length() - 1]) || i == 0))
            spoke.push_back(words[i]);
        else
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    if(spoke.size() == words.size())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}