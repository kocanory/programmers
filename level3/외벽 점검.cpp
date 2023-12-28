#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    int w_size = weak.size();
    for(int i = 0;i < w_size;i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    
    do
    {
        for(int i = 0;i < w_size;i++)
        {
            int start = weak[i], end = weak[i + w_size - 1];
            for(int d = 0;d < dist.size();d++)
            {
                start += dist[d];
                if(start >= end)
                {
                    answer = min(answer, d + 1);
                    break;
                }
                
                for(int k = i + 1; k < i + w_size; k++)
                {
                    if(weak[k] > start)
                    {
                        start = weak[k];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));
    return answer = (answer == 1e9 ? -1 : answer);
}