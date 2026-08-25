#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<int, string>> check;
    
    for(int i = 0;i < cities.size();i++){
        for(auto &c : cities[i])
            c = tolower(c);
        
        bool flag = false;
        for(int idx = 0;idx < check.size();idx++){
            if(check[idx].second == cities[i]){
                check[idx].first = i;
                sort(check.begin(), check.end());
                flag = true;
                answer++;
                break;
            }
        }
        
        if(!flag){
            if(check.size() < cacheSize)
                check.push_back({i, cities[i]});
            else{
                if(cacheSize != 0){
                    check.erase(check.begin(), check.begin() + 1);
                    check.push_back({i, cities[i]});
                }
            }
            answer += 5;
        }
    }
    
    return answer;
}