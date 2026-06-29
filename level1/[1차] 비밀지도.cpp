#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0;i < n;i++){
        int num = arr1[i] | arr2[i];
        string row = "";
        while(num){
            row = (num % 2 ? '#' : ' ') + row;
            num /= 2;
        }
        row = string(n - row.size(), ' ') + row;
        answer.push_back(row);
    }
    
    return answer;
}