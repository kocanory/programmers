#include <vector>

using namespace std;

void recursive(int x, int y, int m, int n, int value, int &size, vector<vector<int>> &picture, vector<vector<bool>> &check)
{
    if(x < 0 || x >= m || y < 0 || y >= n)
        return;
    if(picture[x][y] == value && check[x][y] == false)
    {
        check[x][y] = true;
        size += 1;
        recursive(x - 1, y, m, n, value, size, picture, check);
        recursive(x + 1, y, m, n, value, size, picture, check);
        recursive(x, y + 1, m, n, value, size, picture, check);
        recursive(x, y - 1, m, n, value, size, picture, check);
    }

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<bool> temp(n, false);
    vector<vector<bool>> check(m, temp); 
    
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int size = 0;
            if(check[i][j] == false && picture[i][j] != 0)
            {
                number_of_area++;
                recursive(i, j, m, n, picture[i][j], size, picture, check);
                max_size_of_one_area = max(size, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}