#include <string>
#include <vector>

using namespace std;

vector<int> arr;
vector<double> cum;

void calc(int k){
    arr.push_back(k);
    
    while(k > 1){
        if(k % 2)
            k = k * 3 + 1;
        else
            k /= 2;
        arr.push_back(k);
    }
}

void inte(){
    cum.push_back(0);
    
    for(int i = 0;i < arr.size() - 1;i++)
        cum.push_back((arr[i] + arr[i + 1]) / (double)2);
    
    for(int i = 1;i < cum.size();i++)
        cum[i] += cum[i - 1];
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    calc(k);
    inte();
    
    int n = arr.size() - 1;
    for(auto r : ranges){
        int x1 = r[0], x2 = n + r[1];
        if(x2 < x1) answer.push_back(-1.0);
        else answer.push_back(cum[x2] - cum[x1]);
    }
    
    return answer;
}