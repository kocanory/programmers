#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for(int i = 0;i < arr1.size();i++){
        vector<int> arr;
        for(int j = 0, sum;j < arr2[0].size();j++){
            sum = 0;
            for(int k = 0;k < arr1[0].size();k++)
                sum += arr1[i][k] * arr2[k][j];
            arr.push_back(sum);
        }
        answer.push_back(arr);
    }
    
    return answer;
}