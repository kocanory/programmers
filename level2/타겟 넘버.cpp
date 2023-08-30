#include <string>
#include <vector>

using namespace std;

void dfs(int &answer, int value, int target, vector<int> numbers, int index)
{
    if(index == numbers.size())
    {
        if(value == target)
            answer++;
        return;
    }
    dfs(answer, value + numbers[index], target, numbers, index + 1);
    dfs(answer, value - numbers[index], target, numbers, index + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(answer, 0, target, numbers, 0);
    return answer;
}