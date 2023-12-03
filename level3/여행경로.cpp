#include <string>
#include <vector>

using namespace std;
string route;

void dfs(vector<vector<string>> &tickets, string before, string s, vector<bool> visited)
{
    if(s.length() == (tickets.size() + 1) * 3)
    {
        if(route.empty())
            route = s;
        else if(route > s)
            route = s;
        return;
    }
    for(int i = 0;i < tickets.size();i++)
    {
        if(!visited[i] && tickets[i][0] == before)
        {
            visited[i] = true;
            dfs(tickets, tickets[i][1], s + tickets[i][1], visited);
            visited[i] = false;
         }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    dfs(tickets, "ICN", "ICN", visited);
    for(int i = 0;i < route.length();i+=3)
        answer.push_back(route.substr(i, 3));
    return answer;
}