#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll AtoN(string A){
    ll res = 0;
    for(int i = 0;i < A.size();i++)
        res += char(A[A.size() - 1 - i] - 'a' + 1) * pow(26, i);
    return res;
}

string NtoA(ll N){
    string res = "";
    
    while(N > 0){
        N--;
        res = char(N % 26 + 'a') + res;
        N = N / 26;
    }
    return res;
}

string solution(long long n, vector<string> bans) {
    vector<ll> bans_idx;
    
    for(auto b : bans) bans_idx.push_back(AtoN(b));
    sort(bans_idx.begin(), bans_idx.end());
    
    for(auto b : bans_idx){
        if(b > n) break;
        n++;
    }
    return NtoA(n);
}