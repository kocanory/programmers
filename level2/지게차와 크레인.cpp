#include <string>
#include <vector>

using namespace std;

void checkOut(vector<string> &arr, int x, int y){
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool flag = false;
    
    for(auto [dx, dy] : dir){
        int nx = x + dx, ny = y + dy;
        if(arr[nx][ny] == '0'){
            flag = true;
            break;
        }
    }
    
    if (flag){
        arr[x][y] = '0';
        for(auto [dx, dy] : dir){
            int nx = x + dx, ny = y + dy;
            if(arr[nx][ny] == '1'){
                arr[nx][ny] = '0';
                checkOut(arr, nx, ny);
            }
        }
    }
}

void fork(vector<string> &arr, char box){
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, idx;
    
    for(int i = 1;i < arr.size() - 1;i++){
        for(int j = 1;j < arr[0].size() - 1;j++){
            if(arr[i][j] == box){
                for(auto [dx, dy] : dir){
                    int nx = i + dx, ny = j + dy;
                    if(arr[nx][ny] == '0'){
                        idx.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
    
    for(auto [i, j] : idx)
        checkOut(arr, i, j);
}

void crane(vector<string> &arr, char box){
    for(int i = 1;i < arr.size() - 1;i++){
        for(int j = 1;j < arr[0].size() - 1;j++){
            if(arr[i][j] == box)
            {
                arr[i][j] = '1';
                checkOut(arr, i, j);
            }            
        }
    }
}
    
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    vector<string> arr(storage.size() + 2, string(storage[0].size() + 2, '0'));
    
    for(int i = 0;i < storage.size();i++)
        for(int j = 0;j < storage[0].size();j++)
            arr[i + 1][j + 1] = storage[i][j];
    
    for(auto r : requests){
        if(r.size() == 1)
            fork(arr, r[0]);
        else
            crane(arr, r[0]);
    }
    
    for(int i = 0;i < arr.size();i++)
        for(int j = 0;j < arr[0].size();j++)
            if (arr[i][j] != '0' && arr[i][j] != '1')
                answer++;
    return answer;
}