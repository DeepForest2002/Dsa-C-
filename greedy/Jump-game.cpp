#include <bits/stdc++.h>
using namespace std;

bool jump_game(vector<int> arr)
{
    int mi = 0;
    for (int i = 0; i < arr.size() && i <= mi; i++)
    {
        if (arr[i] + i >= mi)
        {
            mi = arr[i] + i;
        }
    }
    return mi >= arr.size();
}

int main()
{
    vector<int> arr = {3, 2, 1, 0, 4};
    cout << jump_game(arr);
    return 0;
}