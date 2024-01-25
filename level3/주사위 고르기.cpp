#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int N;
vector<int> A, B, Asum, Bsum;
map<pair<set<int>, set<int>>, bool> visited;

void init()
{
    A.clear(); B.clear(); Asum.clear(); Bsum.clear();
}

void func(int idx, int total, bool isA, vector<int> &v, vector<vector<int>> &dice)
{
    if(idx == N / 2)
    {
        isA ? Asum.push_back(total) : Bsum.push_back(total);
        return;
    }
    for(int i = 0;i < 6;i++)
        func(idx + 1, total + dice[v[idx]][i], isA, v, dice);
}

vector<int> solution(vector<vector<int>> dice) {
    N = dice.size();
    vector<int> v(N);
    
    for(int i = 0;i < N;i++) v[i] = i;
    
    vector<int> answer(N / 2);
    int maxWin = 0;
    
    do{
        init();
        int win = 0;
        set<int> Aset, Bset;
        
        for(int i =0;i < N / 2;i++)
        {
            A.push_back(v[i]); Aset.insert(v[i]);
            B.push_back(v[i + N / 2]); Bset.insert(i + N / 2);
        }
        
        if(!visited.count({Aset, Bset}))
        {
            func(0, 0, true, A, dice);
            func(0, 0, false, B, dice);
            
            sort(Bsum.begin(), Bsum.end());
            map<int, int> sum2winCnt;
            
            for(auto a : Asum)
            {
                if(sum2winCnt.count(a))
                {
                    win += sum2winCnt[a];
                    continue;
                }
                int low = 0, high = Bsum.size();
                while(low < high)
                {
                    int mid = (low + high) / 2;
                    if(a > Bsum[mid]) low = mid + 1;
                    else high = mid;
                }
                sum2winCnt[a] = low;
                win += sum2winCnt[a];
            }
            if(win > maxWin)
            {
                for(int i = 0;i < A.size();i++) answer[i] = A[i] + 1;
                maxWin = win;
            }
            visited[{Aset, Bset}] = true;
        }
    }while(next_permutation(v.begin(), v.end()));
    return answer;
}