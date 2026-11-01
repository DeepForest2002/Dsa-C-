#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{
    // insertion sort - 1 . start iteration from the second element as the first element is supposed to be sorted
    // compare first with the second element and if first>second then swap them
    // move to the 3rd element and compare them with the first two element
    // Repeat this process until the whole array is sorted
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    return;
}

int main()
{
    vector<int> arr = {2, 5, 9, 7, 8};
    insertion_sort(arr);
    for (auto el : arr)
    {
        cout << el << endl;
    }
    return 0;
}