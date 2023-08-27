#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto a : skill_trees)
    {
        string sub = "";
        for(auto b : a)
        {
            
            for(auto c : skill)
            {
                if(b == c)
                    sub += b;
            }
        }
        if(skill.find(sub) == 0)
            answer++;
    }
    return answer;
}