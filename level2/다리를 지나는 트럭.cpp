#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, sum = 0;
    vector<pair<int, int>> go;
    while(true)
    {
        if(!go.empty())
        {
            for(auto &a : go)
                a.second++;
            if(go[0].second >= bridge_length)
            {
                sum -= go[0].first;
                go.erase(go.begin());
            }
        }
        if(go.empty() && truck_weights.empty()) break;
        if(!truck_weights.empty() && sum + truck_weights[0] <= weight)
        {
            sum += truck_weights[0];
            go.push_back(make_pair(truck_weights[0], 0));
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
    }
    return answer + 1;
}