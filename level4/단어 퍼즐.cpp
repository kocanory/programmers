#include <iostream>
#include <string>
#include <vector>
#include <string_view>

using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int size = t.length();
    vector<int> dp(size, 1e9);
    
    for(int i = 0;i < size;i++)
    {
        string current = t.substr(0, i + 1);
        for(auto s : strs)
        {
            int diff = current.length() - s.length();
            if(diff < 0) continue;
            bool check = true;
            for(int j = 0;j < s.length();j++)
            {
                if(current[diff + j] != s[j]){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            dp[i] = min(dp[i], dp[diff - 1] + 1);
        }
    }

    return dp[size - 1] == 1e9 ? -1 : dp[size - 1];
}