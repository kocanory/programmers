#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string num = "";
    
    while(n){
        num = to_string(n % k) + num;
        n /= k;
    }
    
    vector<string> arr;
    stringstream ss(num);
    string s;
    
    while(getline(ss, s, '0'))
        arr.push_back(s);
    
    for(auto a : arr){
        if(a != ""){
            bool flag = true;
            long long val = stoll(a);
            for(int i = 2;i < int(sqrt(val)) + 1;i++){
                if(val % i == 0){
                    flag = false;
                    break;
                }
            }
            if(flag && val != 1)
                answer++;
        }
    }
    
    return answer;
}