#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    vector<int> left(size);
    vector<int> right(size);
    
    int Min = a[0];
    for(int i = 0;i < size;i++)
    {
        if(Min > a[i]) Min = a[i];
        left[i] = Min;
    }
    
    Min = a.back();
    for(int i = size - 1;i >= 0;i--)
    {
        if(Min > a[i]) Min = a[i];
        right[i] = Min;
    }
    
    for(int i = 0;i < size;i ++)
    {
        if (a[i] <= left[i] || a[i] <= right[i]) answer++;
    }
    return answer;
}