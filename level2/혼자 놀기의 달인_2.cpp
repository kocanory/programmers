#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> visit(cards.size(), false);
    vector<int> arr;    
    for(auto a : cards)
    {
        int count = 0;
        a = a - 1;
        while(!visit[a])
        {
            count++;
            visit[a] = true;
            a = cards[a] - 1;
        }
        arr.push_back(count);
    }
    if(arr.size() == 1) return 0;
    sort(arr.begin(), arr.end(), greater<int>());
    
    return answer = arr[0] * arr[1];
}