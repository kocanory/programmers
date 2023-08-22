#include <string>
#include <vector>
#include <sstream>

using namespace std;
bool isSame(string &m, string &temp)
{
    int idx;
    for(int i = 0;i<m.length();i++)
    {
        if((idx = m.find(temp, i)) != -1 && m[idx + temp.length()] != '#')
            return true;
    }
    for(int i = 0;i<temp.length();i++)
    {
        if((idx = temp.find(m, i)) != -1 && temp[idx + m.length()] != '#')
            return true;
    }
    return false;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int time = 0;
    for(auto a : musicinfos)
    {
        stringstream ss(a);
        string s = "";
        vector<string> vec;
        int play = 0;
        while(getline(ss, s, ','))
            vec.push_back(s);
        
        stringstream t1(vec[0]);
        int n = 60;
        while(getline(t1, s, ':'))
        {
            play -= (stoi(s) * n);
            n /= 60;
        }
        
        stringstream t2(vec[1]);
        n = 60;
        while(getline(t2, s, ':'))
        {
            play += (stoi(s) * n);
            n /= 60;
        }
        if(time >= play) continue;
        int length = 0;
        for(auto a: vec[3])
            if(a != '#')
                length++;
        int count = 0;
        if(play >= length)
        {
            for(int i = 0;;i++)
            {
                vec[3] += vec[3][i];
                if(vec[3][(i + 1)] == '#')
                {
                    vec[3] += '#';
                    i++;
                }
                count++;
                if(count >= play - length)
                    break;
            }
        }
        else
        {
            string temp = "";
            for(int i = 0;;i++)
            {
                temp += vec[3][i];
                if(vec[3][(i + 1)] == '#')
                {
                    temp += '#';
                    i++;
                }
                count++;
                if(count >= play)
                    break;
            }
            vec[3] = temp;
        }
  
        if(isSame(m, vec[3]))
        {
            answer = vec[2];
            time = play;
        }
            
    }
    return answer = (answer == "") ? "(None)" : answer;
}