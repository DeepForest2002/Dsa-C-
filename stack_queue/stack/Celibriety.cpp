#include <bits/stdc++.h>
using namespace std;

int find_celibrity(vector<vector<int>> arr)
{
    // this is a brute force approach
    vector<int> know_me(arr.size(), 0);
    vector<int> iKnow(arr.size(), 0);

    int row = arr.size();
    int col = arr[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 1)
            {
                know_me[j]++;
                iKnow[i]++;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (iKnow[i] == 0 && know_me[i] == row - 1)
            return i;
    }
    return -1;
}

int find_celibrity_optimal(vector<vector<int>> arr)
{
    int n = arr.size();
    int top = 0;
    int down = n - 1;
    while (top < down)
    {
        if (arr[top][down] == 1)
            top++;
        else if (arr[down][top] == 1)
            down--;
        else
        {
            top++;
            down--;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[top][i] == 1 || arr[i][top] == 0)
            return -1;
    }
    return top;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int ans = find_celibrity_optimal(arr);
    cout << ans;
    return 0;
}