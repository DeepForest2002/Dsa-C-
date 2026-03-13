#include <bits/stdc++.h>
using namespace std;

void move_zeros(vector<int> &arr)
{
    int j;
    // find the first pos of 0
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    // if the val of j is size-1
    if (j == arr.size() - 1)
        return;
    for (int i = j + 1; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j += 1;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 0};
    move_zeros(arr);
    for (auto el : arr)
    {
        cout << el << " ";
    }
    return 0;
}