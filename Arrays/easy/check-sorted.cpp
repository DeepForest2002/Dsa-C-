#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            count += 1;
    }
    if (arr[arr.size() - 1] > arr[0])
        count += 1;
    return count <= 1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << isSorted(arr);
    return 0;
}