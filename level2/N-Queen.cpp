#include <string>
#include <vector>
#include <cmath>

using namespace std;
int arr[12];

bool valid(int depth)
{
    for(int i = 0;i<depth;i++)
    {
        if(arr[i] == arr[depth]) return false;
        if(abs(depth - i) == abs(arr[depth] - arr[i])) return false;
    }
    return true;
}

void backtracking(int &answer, int depth, int n)
{
    if(depth == n)
    {
        answer++;
        return;
    }
    for(int i = 0;i<n;i++)
    {
        arr[depth] = i;
        if(valid(depth))
        {
            backtracking(answer, depth + 1, n);
        }
    }
}

int solution(int n) {
    int answer = 0;
    backtracking(answer, 0, n);
    return answer;
}