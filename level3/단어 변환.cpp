#include <string>
#include <vector>

using namespace std;
int answer = 1e9;

void dfs(int count, string word, string target, vector<string> &words, vector<bool> visit)
{
    if(word == target)
    {
        answer = min(answer, count);
        return;
    }
    for(int i = 0;i<words.size();i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            int same = 0;
            for(int j = 0;j < words[i].length();j++)
            {
                if(word[j] == words[i][j])
                    same++;
            }
            if(same == words[i].size() - 1)
            {
                dfs(count + 1, words[i], target, words, visit);
            }
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visit(words.size(), false);
    dfs(0, begin, target, words, visit);
    if(answer == 1e9) return 0;
    return answer;
}