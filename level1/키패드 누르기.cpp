#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 10, r = 12;
    
    for(auto n : numbers){
        if (n == 0) n = 11;
        if (n % 3 == 1){
            l = n;
            answer += 'L';
        }
        else if(n % 3 == 0){
            r = n;
            answer += 'R';
        }
        else{
            int nx = (n - 1) / 3, ny = (n - 1) % 3;
            int lx = (l - 1) / 3, ly = (l - 1) % 3;
            int rx = (r - 1) / 3, ry = (r - 1) % 3;
            int ld = abs(lx - nx) + abs(ly - ny), rd = abs(rx - nx) + abs(ry - ny);
            
            if(ld == rd){
                if(hand == "left"){
                    l = n;
                    answer += 'L'; 
                }
                else{
                    r = n;
                    answer += 'R';
                }
            }
            else if(ld < rd){
                l = n;
                answer += 'L';
            }
            else{
                r = n;
                answer += 'R';
            }
        }
    }
    return answer;
}