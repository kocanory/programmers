#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
map<vector<string>, int> m;

void dfs(int &answer, int count, vector<string> val, vector<bool> visit, vector<string> &user_id, vector<string> &banned_id)
{
    if(count >= banned_id.size())
    {
        sort(val.begin(), val.end());
        m[val]++;
        return;
    }
    for(int i = 0;i < user_id.size(); i++)
    {
        if(visit[i]) continue;
        if(user_id[i].length() != banned_id[count].length()) continue;
        bool flag = true;
        for(int j = 0;j < banned_id[count].length();j++)
        {
            if(banned_id[count][j] != '*' && user_id[i][j] != banned_id[count][j])
            {
                flag = false;
                break;
            }
        }
        if(flag) 
        {
            visit[i] = true;
            val.push_back(user_id[i]);
            dfs(answer, count + 1, val, visit, user_id, banned_id);
            val.pop_back();
            visit[i] = false;
         }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<bool> visit(user_id.size(), false);
    vector<string> val;
    dfs(answer, 0, val, visit, user_id, banned_id);
    return answer = m.size();
}