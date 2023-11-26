#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
bool comp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

struct comp_pq{
   bool operator()(pair<int, int> a, pair<int, int> b){
       if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    } 
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genre_sum;
map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, comp_pq>>genre_pq;
    vector<int> answer;
    for(int i = 0;i<genres.size();i++)
    {
        genre_sum[genres[i]] += plays[i];
        genre_pq[genres[i]].push({i, plays[i]});
    }
    vector<pair<string, int>> vec(genre_sum.begin(), genre_sum.end());
    sort(vec.begin(), vec.end(), comp);
    for(int i = 0 ;i < vec.size();i++)
    {
        int count = 0;
        while(!genre_pq[vec[i].first].empty() && count < 2)
        {
            int play = genre_pq[vec[i].first].top().first;
            genre_pq[vec[i].first].pop();
            answer.push_back(play);
            count++;
        }
    }
    return answer;
}