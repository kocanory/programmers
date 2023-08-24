#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    
    vector<vector<int>> arr;
    
    for(int i = 0;i<rows;i++)
    {
        vector<int> temp;
        for(int j = i * columns + 1;j <= i * columns + columns;j++)
            temp.push_back(j);
        arr.push_back(temp);
    }
    
    for(auto q : queries)
    {
        int direction = 0;
        pair<int, int> now = make_pair(q[0] - 1, q[1]);
        vector<vector<int>> back = arr;
        int val = 10001;
        while(true)
        {
            val = min(val, arr[now.first][now.second]);
            arr[now.first][now.second] = back[now.first - dx[direction]][now.second - dy[direction]];
            if(now.first == q[0] - 1 && now.second == q[1] - 1)
                break;
            if(now.first + dx[direction] < q[0] - 1 || now.first + dx[direction] >= q[2] || now.second + dy[direction] < q[1] - 1 || now.second + dy[direction] >= q[3])
                direction++;
            now.first += dx[direction];
            now.second += dy[direction];
        }
        answer.push_back(val);
    }
    return answer;
}