#include <string>
#include <vector>
#include <sstream>

using namespace std;

int convertTime(string t)
{
    stringstream ss(t);
    string s;
    vector<double> arr;
    while(getline(ss, s, ':'))
        arr.push_back(stod(s));
    return (int)((arr[0] * 3600 + arr[1] * 60 + arr[2]) * 1000);
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int, int>> times;
    for(auto l : lines)
    {
        vector<string> arr;
        string t = l.substr(11);
        stringstream ss(t);
        string s;
        while(ss >> s) arr.push_back(s);
        int end = convertTime(arr[0]);
        int start = end - 1000 * stod(arr[1].substr(0, arr[1].length() - 1)) + 1;
        times.push_back({start, end});
    }

    for(auto p : times)
    {
        int process = p.second;
        int count = 0;
        for(auto t : times)
            if(t.first <= process + 999 && t.second >= process)
                count++;
        answer = max(answer, count);
    }
    
    for(auto p : times)
    {
        int process = p.first;
        int count = 0;
        for(auto t : times)
            if(t.first <= process + 999 && t.second >= process)
                count++;
        answer = max(answer, count);
    }
    return answer;
}