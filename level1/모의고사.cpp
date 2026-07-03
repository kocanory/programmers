#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int cntMax = 0, cnt;
    
    cnt = 0;
    vector<int> answer1 = {1, 2, 3, 4, 5};
    for(int i = 0;i < answers.size();i++)
        if(answer1[i % answer1.size()] == answers[i])
            cnt++;
    
    if(cntMax <= cnt){
        if(cntMax < cnt){
            answer.clear();
            cntMax = cnt;
        }
        answer.push_back(1);
    }
    
    cnt = 0;
    vector<int> answer2 = {2, 1, 2, 3, 2, 4, 2, 5};
    for(int i = 0;i < answers.size();i++)
        if(answer2[i % answer2.size()] == answers[i])
            cnt++;
    
    if(cntMax <= cnt){
        if(cntMax < cnt){
            answer.clear();
            cntMax = cnt;
        }
        answer.push_back(2);
    }
    
    cnt = 0;
    vector<int> answer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for(int i = 0;i < answers.size();i++)
        if(answer3[i % answer3.size()] == answers[i])
            cnt++;
    
    if(cntMax <= cnt){
        if(cntMax < cnt){
            answer.clear();
            cntMax = cnt;
        }
        answer.push_back(3);
    }
    
    return answer;
}