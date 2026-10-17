#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
vector<int> tmp;

void hanoi(int n, int from, int mid, int to){
    if(n == 1){
        tmp = {from, to};
        answer.push_back(tmp);
        return;
    }
    hanoi(n - 1, from, to, mid);
    tmp = {from, to};
    answer.push_back(tmp);
    hanoi(n - 1, mid, from, to);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return answer;
}