#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr)
{
    int first_el = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = first_el;
    return;
}

// rotate array by d places in left side
void rotate(vector<int> &arr, int d)
{
    int n = arr.size();
    d %= n;
    // reverse d element first
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    left_rotate(arr);
    return 0;
}