#include <string>
#include <vector>

using namespace std;

char conv(int n){
    if(n >= 10) return char(n - 10 + 'A');
    return n + '0';
}

string solution(int n, int t, int m, int p) {
    string answer = "", arr = "0";
    int num = 1;
    
    while(arr.size() < t * m){
        int tmp = num;
        string s = "";
        
        while(tmp){
            s = conv(tmp % n) + s;
            tmp /= n;
        }
        
        arr += s;
        num++;
    }
    
    for(int i = p - 1;i < t * m;i += m)
        answer += arr[i];
    
    return answer;
}