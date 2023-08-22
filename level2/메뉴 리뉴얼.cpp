#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
bool visit[20];
map<string, int> ans;

void dfs(int index, int count, string& order, string item)
{
    if(count >= 2 && count <= 10)
    {
        string temp = item;
        sort(temp.begin(), temp.end());
        ans[temp]++;
    }
    else if(count > 10)
        return;
    for(int i = index;i<order.size();i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            dfs(i + 1, count + 1, order, item + order[i]);
            visit[i] = false;
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto &a : orders)
        dfs(0, 0, a, "");
    for(auto &c : course)
    {
        int max_count = 0;
        for(auto iter = ans.begin();iter != ans.end();iter++)
        {
            if(iter->first.size() == c)
                max_count = max(max_count, iter -> second);
        }
        if(max_count == 1)
            continue;
        for(auto iter = ans.begin();iter != ans.end();iter++)
        {
            if(iter->first.size() == c && iter -> second == max_count)
                answer.push_back(iter->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}