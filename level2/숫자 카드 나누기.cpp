#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0, gcdA, gcdB;
    bool flagA = true, flagB = true;
    
    gcdA = (arrayA.size() == 1 ? arrayA[0] : gcd(arrayA[0], arrayA[1]));
    gcdB = (arrayB.size() == 1 ? arrayB[0] : gcd(arrayB[0], arrayB[1]));
    
    for(int i = 2;i < arrayA.size();i++) gcdA = gcd(gcdA, arrayA[i]);
    for(int i = 2;i < arrayB.size();i++) gcdB = gcd(gcdB, arrayB[i]);
    
    for(auto a : arrayA)
        if(gcdB == 1 || a % gcdB == 0){
            flagA = false;
            break;
        }
    
    for(auto b : arrayB)
        if(gcdA == 1 || b % gcdA == 0){
            flagB = false;
            break;
        }
    
    if(flagA && flagB) answer = max(gcdA, gcdB);
    else if(flagA) answer = gcdB;
    else if(flagB) answer = gcdA;
    
    return answer;
}