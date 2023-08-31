#include <string>
#include <vector>
#include <sstream>

using namespace std;
#include <algorithm>

bool compare(string a, string b)
{
    return a.length() < b.length();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> arr;
    string str = "";
    for(int i = 1;i<s.length() - 1;i++)
    {
        if(s[i] == '{') continue;
        else if(s[i] == '}') 
        {
            arr.push_back(str);
            str.clear();
            i++;
        }
        else str += s[i];
    }
    
    sort(arr.begin(), arr.end(), compare);
    
    for(auto a : arr)
    {
        stringstream ss(a);
        string temp = "";
        while(getline(ss, temp, ','))
            if(find(answer.begin(), answer.end(), stoi(temp)) == answer.end())
                answer.push_back(stoi(temp));
        
    }
    return answer;
}