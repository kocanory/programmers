#include <string>
#include <cctype>
#include <vector>

using namespace std;
const string ivd = "invalid";

string rule1(string str)
{
    string ret;
    if(str.size() < 3) return "-1";
    char c = str[1];
    bool check = false;
    for(int i = 0;i < str.size();i++)
    {
        if(islower(str[i])) check = true;
        if(i % 2 == 0)
        {
            if(islower(str[i])) return "-1";
            ret += str[i];
        }
        else
        {
            if(c != str[i]) return "-1";
        }
    }
    if(!check) return "-1";
    return ret;
}

string allUpper(string str)
{
    for(auto s : str)
    {
        if(!isupper(s)) return "-1";
    }
    return str;
}

string solution(string sentence) {
    string answer = "";
    vector<bool> used(26, false);
    int index = 0;
    while(!sentence.empty())
    {
        string ret;
        vector<int> pos;
        if(islower(sentence[0]))
        {
            if(used[sentence[0] - 'a']) return ivd;
            used[sentence[0] - 'a'] = true;
            for(int i = 0;i < sentence.length();i++)
                if(sentence[i] == sentence[0])
                    pos.push_back(i);
            
            if(pos.size() != 2) return ivd;
            
            string center = sentence.substr(1, pos.back() - 1);
            if(center == "") return ivd;
            ret = rule1(center);
            string target;
            if(ret == "-1"){
                ret = allUpper(center);
                if(ret == "-1") return ivd;
            }
            else
            {
                if(used[sentence[2] - 'a']) return ivd;
                used[sentence[2] - 'a'] = true;
            }
            sentence = sentence.substr(pos.back() + 1);
        }
        else
        {
            if(sentence.length() == 1 || isupper(sentence[1])){
                ret = sentence[0];
                sentence = sentence.substr(1);
            }
            else
            {
                for(int i = 0;i < sentence.size();i++){
                    if(sentence[1] == sentence[i])
                        pos.push_back(i);
                }
                if(pos.size() != 2)
                {
                    if(pos.back() == sentence.size() - 1) return ivd;
                    if(islower(sentence[pos.back() + 1])) return ivd;
                    string center = sentence.substr(0, pos.back() + 2);
                    ret = rule1(center);
                    if(ret=="-1") return ivd;
                    if(used[sentence[1] - 'a']) return ivd;
                    used[sentence[1] - 'a'] = true;
                    sentence = sentence.substr(pos.back() + 2);
                }
                else{
                    ret = sentence[0];
                    sentence=sentence.substr(1);
                }
            }
        }
        answer += ret + " ";
    }
    answer.pop_back();
    return answer;
}