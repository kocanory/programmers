#include <string>
#include <vector>
#include <map>

using namespace std;

string s = "ACFJMNRT";
map<char, bool> visited;
int answer = 0;

bool check(int d1, int d2, char op){
    if(op == '=' && d1 == d2) return true;
    if(op == '>' && d1 > d2) return true;
    if(op == '<' && d1 < d2) return true;
    return false;
}

void solve(string now, vector<string> &data){
    if(now.size() >= 8){
        bool flag = true;
        for(auto d : data){
            int d1 = abs(int(now.find(d[0])) - int(now.find(d[2]))) - 1, d2 = d[4] - '0';
            
            if(!check(d1, d2, d[3])){
                flag = false;
                break;
            }
        }
        if(flag) answer++;
        return;
    }
    
    for(auto a : s){
        if(!visited[a]){
            visited[a] = true;
            solve(now + a, data);
            visited[a] = false;
        }
    }
}

int solution(int n, vector<string> data) {
    answer = 0;
    solve("", data);
    return answer;
}