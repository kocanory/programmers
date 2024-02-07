#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> room;

long long findroom(long long number)
{
    if(!room[number])
    {
        room[number] = number + 1;
        return number;
    }
    
    long long emptyroom = findroom(room[number]);
    room[number] = emptyroom + 1;
    return emptyroom;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(auto r : room_number)
        answer.push_back(findroom(r));
    return answer;
}