#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<int> arr(w);
    
    for(int i = 0;i < n;i++){
        if((i / w) % 2) arr[w - 1 - i % w]++;
        else arr[i % w]++;
    }
    
    if(((num - 1) / w) % 2) answer = arr[w - 1 - (num - 1) % w] - (num - 1) / w;
    else answer = arr[(num - 1) % w] - (num - 1) / w;
    return answer;
}