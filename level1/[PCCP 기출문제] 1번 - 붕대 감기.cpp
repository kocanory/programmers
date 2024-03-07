#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int count = 0;
    int health_max = health;
    for(int i  = 1;;i++){
        if(i > attacks.back()[0]) return health;
        bool flag = true;
        for(auto a : attacks){
            if(a[0] == i){
                health -= a[1];
                flag = false;
                count = 0;
                break;             
            }
        }
        if(health <= 0) return -1;
        if(flag){
            count++;
            if(health_max - health >= bandage[1])
                health += bandage[1];
            else
                health = health_max;
            if(count == bandage[0]){
                if(health_max - health >= bandage[2])
                    health += bandage[2];
                else
                    health = health_max;
                count = 0;
            }
        }
    }    
}