#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> arr;

bool check(int y){
    for(int i = 0;i < y;i++)
        if(arr[i] == arr[y] || abs(i - y) == abs(arr[i] - arr[y]))
            return false;
    return true;
}

void solve(int y, int n){
    if(y == n){
        answer++;
        return;
    }
    
    for(int i = 0;i < n;i++){
        arr[y] = i;
        if(check(y))
            solve(y + 1, n);
    }
}

int solution(int n) {
    arr.assign(n, 0);
    solve(0, n);
    return answer;
}