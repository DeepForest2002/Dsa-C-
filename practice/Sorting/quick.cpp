#include <bits/stdc++.h>
using namespace std;

int partition_index(vector<int> &arr, int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition_index(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main()
{
    vector<int> arr = {9, 4, 7, 3, 1};
    quick_sort(arr, 0, arr.size() - 1);
    for (auto el : arr)
    {
        cout << el << endl;
    }
    return 0;
}