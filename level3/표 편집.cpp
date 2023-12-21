#include <string>
#include <vector>

using namespace std;

typedef struct{
    int val = -1;
    int prev = -1;
    int next = -1;
}Node;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<Node> node(n);
    vector<Node> deleted;
    
    for(int i = 0;i < n;i++)
    {
        answer += "O";
        node[i].val = i;
        if(i > 0) node[i].prev = i - 1;
        if(i < n - 1) node[i].next = i + 1;
    }
    
    for(auto c : cmd)
    {
        char command = c[0];
        int move = 0;
        if(c.length() > 1) move = stoi(c.substr(2));
        
        if(command == 'U')
        {
            while(move--) k = node[k].prev;
        }
        else if(command == 'D')
        {
            while(move--) k = node[k].next;
        }
        else if(command == 'C')
        {
            int next = node[k].next;
            int prev = node[k].prev;
            
            deleted.push_back(node[k]);
            
            if(prev > -1) node[prev].next = next;
            if(next > -1) node[next].prev = prev;
            
            k = next > -1 ? next : prev;
        }
        else
        {
            Node recovery = deleted.back();
            deleted.pop_back();
            
            int val = recovery.val;
            int prev = recovery.prev;
            int next = recovery.next;
            
            if(prev > -1)
                node[prev].next = val;
            if(next > -1)
                node[next].prev = val;
        }
    }
    for(auto d : deleted)
        answer[d.val] = 'X';
    return answer;
}