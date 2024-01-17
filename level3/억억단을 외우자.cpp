#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    vector<int> vNum(e + 1);
    vector<int> vCnt(e + 1);
    
    for(int i = 1;i <= e;i++)
        for(int j = i;j <= e;j += i)
            vNum[j]++;
    
    vector<int> ns = starts;
    sort(ns.begin(), ns.end(), greater<int>());
    
    map<int, set<int>, greater<int>> vMap;
    int limit = e + 1;
    
    for(auto s : ns)
    {
        for(int j = s;j < limit;j++)
            vMap[vNum[j]].insert(j);
        vCnt[s] = *(vMap.begin()->second.begin());
        limit = s;
    }
    
    for(auto s : starts)
        answer.push_back(vCnt[s]);
    return answer;
}