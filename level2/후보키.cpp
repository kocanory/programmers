#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> keys;
vector<vector<int>> candidate;
vector<vector<string>> relate;
int x = 0, y = 0;

void Makekey(int num)
{
    if(num == x) return;
    int size = keys.size();
    for(int i = 0;i < x;i++)
    {
        if(num == 0)
        {
            vector<int> arr;
            arr.push_back(i);
            keys.push_back(arr);
        }
        else
        {
            for(int j = 0;j<size;j++)
            {
                if(keys[j].size() == num)
                {
                    vector<int> arr;
                    for(int k = 0;k<num;k++)
                    {
                        if(keys[j][k] != i)
                            arr.push_back(keys[j][k]);
                        else
                            break;                
                    }
                    if(arr.size() == num)
                    {
                        arr.push_back(i);
                        sort(arr.begin(), arr.end());
                        if(find(keys.begin(), keys.end(), arr) == keys.end())
                            keys.push_back(arr);
                    }
                }
            }
        }
    }
    Makekey(num + 1);
}

bool isCandidate(vector<int> check)
{
    for(int i = 0;i < y - 1;i++)
    {
        string a = "";
        for(int j = 0;j<check.size();j++)
            a = a + relate[i][check[j]] + "_";
        for(int k = i + 1;k < y;k++)
        {
            string b = "";
            for(int l = 0;l<check.size();l++)
                b = b + relate[k][check[l]] + "_";
            if(a == b) return false;
        }
    }
    return true;
}

void findCandidate()
{
    int size = keys.size();
    for(int i = 0;i<size;i++)
    {
        if(isCandidate(keys[i]) == true)
        {
            candidate.push_back(keys[i]);
            for(int j = size - 1;j > i;j--)
            {
                int same = 0;
                for(int k = 0;k<keys[i].size();k++)
                    for(int l = 0;l<keys[j].size();l++)
                        if(keys[i][k] == keys[j][l])
                            same++;
                if(same == keys[i].size()) {
                    keys.erase(keys.begin() + j);
                    size--;
                }
            }
        }
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    relate = relation;
    x = relate[0].size();
    y = relate.size();
    
    Makekey(0);
    findCandidate();
    answer = candidate.size();
    return answer;
}