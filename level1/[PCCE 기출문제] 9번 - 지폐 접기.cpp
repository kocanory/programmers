#include <string>
#include <vector>

using namespace std;

int minVal(vector<int> &v){
   return min(v[0], v[1]);
}

int maxVal(vector<int> &v){
    return max(v[0], v[1]);
}

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    while(minVal(wallet) < minVal(bill) || maxVal(wallet) < maxVal(bill)){
        if(bill[0] < bill[1]) bill[1] /= 2;
        else bill[0] /= 2;
        answer++;
    }
    return answer;
}