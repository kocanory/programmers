#include <string>
#include <vector>

using namespace std;
vector<int> arr;
int Max = -1;
bool flag = false;

void recursive(int n, vector<int> &info, vector<int> point)
{
    if(point.size() > 11) return;
    if(n == 0)
    {
        int apeach = 0, ryan = 0;
        while(point.size() < 11)
            point.push_back(0);
        
        for(int i = 0;i < point.size();i++)
        {
            if(point[i] == 0 && info[i] == 0)
                continue;
            if(point[i] > info[i])
                ryan += ((10 - i));
            else
                apeach += ((10 - i));
        }
        
        if(ryan <= apeach) return;
        
        flag = true;
            
        if(ryan - apeach > Max)
        {
            Max = ryan - apeach;
            arr = point;
        }
        else if(ryan - apeach == Max)
        {
            int i = 10, j = 10;
            while(point[i] == 0) i--;
            while(arr[j] == 0) j--;
            if(i > j)
            {
                arr = point;
            }
        }
        return;
    }
    
    for(int i = 0;i <= n;i++)
    {
        point.push_back(i);
        recursive(n - i, info, point);
        point.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    vector<int> point;
    recursive(n, info, point);
    
    if(!flag)
    {
        answer.push_back(-1);
    }
    else
    {
        answer = arr;
    }
    return answer;
}