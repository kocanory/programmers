#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    for(auto &a : str1)
        a = tolower(a);
    for(auto &a : str2)
        a = tolower(a);
    
    vector<string> arr1, arr2, arr3;
    
    for(int i = 0;i<str1.length() - 1;i++)
    {
        if((str1[i] >= 'a' && str1[i] <= 'z') && (str1[i + 1] >= 'a' && str1[i + 1] <= 'z'))
        {
            arr1.push_back(str1.substr(i, 2));
        }
    }
    
    for(int i = 0;i<str2.length() - 1;i++)
    {
        if((str2[i] >= 'a' && str2[i] <= 'z') && (str2[i + 1] >= 'a' && str2[i + 1] <= 'z'))
        {
            arr2.push_back(str2.substr(i, 2));
        }
    }
    
    int arr1_size = arr1.size();
    int arr2_size = arr2.size();
    
    if(arr1_size == 0 && arr2_size == 0)
        return 65536;
    
    for(int i = 0;i<arr1.size();i++)
    {
        for(int j = 0;j<arr2.size();j++)
        {
            if(arr1[i] == arr2[j])
            {
                arr3.push_back(arr1[i]);
                arr1.erase(arr1.begin() + i);
                arr2.erase(arr2.begin() + j);
                i--;
                j--;
            }
        }
    }
    return answer = 65536 * arr3.size() / (arr1_size + arr2_size - arr3.size());
}