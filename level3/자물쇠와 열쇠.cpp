#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int>> rotate(vector<vector<int>> &key)
{
    int size = key.size();
    vector<vector<int>> arr(size, vector<int>(size, 0));
    for(int i = 0; i < size; i++)
        for(int j = 0;j < size; j++)
            arr[i][j] = key[size - 1 - j][i];
    
    return arr;
}

bool isOpen(vector<vector<int>> &key, vector<vector<int>> &lock, int right, int down, int emptyCount)
{
    for(int i = 0;i < key.size();i++)
    {
        if(i + down >= lock.size() || i + down < 0)
            continue;
        for(int j = 0;j < key.size();j++)
        {
            if(j + right >= lock.size() || j + right < 0)
                continue;
            if(key[i][j] == lock[i + down][j + right])
                return false;
            if(lock[i + down][j + right] == 0)
                emptyCount--;
        }
    }
    if(emptyCount == 0)
        return true;
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<vector<int>>> rotated;
    rotated.push_back(key);
    for(int i = 1;i < 4;i++)
        rotated.push_back(rotate(rotated.back()));
    
    int emptyCount = 0;
    for(auto i : lock)
        for(auto j : i)
            if(j == 0)
                emptyCount++;

    if(emptyCount == 0) return true;
    
    int a = lock.size();
    for(int right = 1;right < lock.size() + key.size();right++)
    {
        for(int down = 1;down < lock.size() + key.size();down++)
        {
            for(auto r : rotated)
                if(isOpen(r, lock, right - key.size(), down - key.size(), emptyCount))
                    return true;
        }
    }
    return false;
}