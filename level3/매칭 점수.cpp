#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct page{
    int idx;
    int basic_p;
    vector<string> out_link;
    double link_p;
    double match_p;
}page;

string Word;
map<string, int> page_num;
vector<page> Pages;

bool comp(page a, page b)
{
    if(a.match_p >= b.match_p)
    {
        if(a.match_p == b.match_p)
        {
            if(a.idx < b.idx)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

string to_lower(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

string find_url(string s)
{
    string target = "<meta property=\"og:url\" content=\"https://";
    int idx = s.find(target);
    idx += target.length();
    string url = "";
    while(s[idx] != '\"') url += s[idx++];
    return url;
}

int find_word(string s)
{
    string target1 = "<body>", target2 = "/<body>";
    int idx1 = s.find(target1), idx2 = s.find(target2);
    s = s.substr(idx1, idx2 - idx1);
    
    string cur = "";
    int count = 0;
    for(auto c : s)
    {
        if(isalpha(c) == 0){
            if(cur == Word) count++;
            cur = "";
        }
        else cur += c;
    }
    return count;
}

vector<string> find_outlink(string s)
{
    vector<string> result;
    string target = "<a href=\"https://";
    int idx = s.find(target);
    while(idx != -1)
    {
        idx += target.length();
        string cur = "";
        while(s[idx] != '\"') cur += s[idx++];
        result.push_back(cur);
        s = s.substr(idx);
        idx = s.find(target);
    }
    return result;
}

void calc_link()
{
    for(auto p : Pages)
    {
        vector<string> arr = p.out_link;
        int size = arr.size();
        for(auto a : arr)
        {
            if(page_num[a] == 0) continue;
            int target_idx = page_num[a] - 1;
            Pages[target_idx].link_p += ((double)p.basic_p / (double)size);
        }
    }
    for(auto &p : Pages)
        p.match_p = (double)p.basic_p + (double)p.link_p;
    sort(Pages.begin(), Pages.end(), comp);
}

void func(vector<string> vec)
{
    for(int i = 0;i < vec.size();i++)
    {
        string s = to_lower(vec[i]);
        string url = find_url(s);
        page_num[url] = i + 1;
        int bp = find_word(s);
        vector<string> out_link = find_outlink(s);
        Pages.push_back({i, bp, out_link, 0.0, 0.0});
    }
    calc_link();
}

int solution(string word, vector<string> pages) {
    int answer = 0;
    Word = to_lower(word);
    func(pages);
    answer = Pages[0].idx;
    return answer;
}