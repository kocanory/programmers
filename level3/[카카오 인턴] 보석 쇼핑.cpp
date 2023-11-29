#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int head = 0, end = 0;
    int headMin = 0, endMin = 0;
    
    for(int i = 0;i < gems.size();i++)
    {
        m[gems[i]]++;
        end = i;
        if(m[gems[i]] == 1)
        {
            headMin = head;
            endMin = end;
        }
        else
        {
            for(int j = head;j < i;j++)
            {
                if(m[gems[j]] > 1)
                {
                    m[gems[j]]--;
                }
                else
                {
                    head = j;
                    if((end - head) < (endMin - headMin))
                    {
                        headMin = head;
                        endMin = end;
                    }
                    break;
                }
            }
        }
    }
    answer.push_back(headMin + 1);
    answer.push_back(endMin + 1);    
    return answer;
}