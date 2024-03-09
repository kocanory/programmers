#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<string, int> index;
vector<int> take, point;
vector<vector<int>> gift;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i = 0;i < friends.size();i++)
        index[friends[i]] = i;
    int size = friends.size();
    take.resize(size, 0);
    point.resize(size, 0);
    gift.resize(size, vector<int> (size, 0));
    
    for(auto g : gifts){
        stringstream ss(g);
        string s;
        vector<string> arr;
        while(ss >> s) arr.push_back(s);
        gift[index[arr[0]]][index[arr[1]]]++;
        point[index[arr[0]]]++;
        point[index[arr[1]]]--;
    }

    for(int i = 0;i < size;i++){
        int first = index[friends[i]];
        for(int j = i + 1;j < size;j++){
            int second = index[friends[j]];
            if(gift[first][second] > gift[second][first]) take[first]++;
            else if(gift[first][second] < gift[second][first]) take[second]++;
            else{
                if(point[first] > point[second])
                    take[first]++;
                else if(point[first] < point[second])
                    take[second]++;
            }
        }
    }

    sort(take.begin(), take.end());
    return answer = take.back();
}