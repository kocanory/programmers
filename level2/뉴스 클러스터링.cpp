#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    double answer = 0, s1 = 0, s2 = 0, cnt = 0;
    map<string, int> m1, m2;
    
    for(auto &a : str1) a = tolower(a);
    for(auto &a : str2) a = tolower(a);
    
    for(int i = 0;i < str1.size() - 1;i++){
        if(isalpha(str1[i]) && isalpha(str1[i + 1])){
            s1++;
            m1[str1.substr(i, 2)]++;
        }
    }
    
    for(int i = 0;i < str2.size() - 1;i++){
        if(isalpha(str2[i]) && isalpha(str2[i + 1])){
            s2++;
            m2[str2.substr(i, 2)]++;
        }
    }
    
    for(auto [k, v] : m1)
        cnt += min(v, m2[k]);
    
    answer = (!m1.size() && !m2.size() ? 1 : cnt / (double)(s1 + s2 - cnt));
    
    return int(answer * 65536);
}