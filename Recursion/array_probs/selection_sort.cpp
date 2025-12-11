#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
    return;
}

void recursive_selection_sort(vector<int> &arr, int n, int i)
{
    if (i >= n - 1)
        return;
    int minIndex = i;
    int j = i + 1;
    for (; j < n; j++)
    {
        if (arr[j] < arr[minIndex])
            minIndex = j;
    }
    swap(arr[minIndex], arr[i]);
    recursive_selection_sort(arr, n, i += 1);
}

int main()
{
    vector<int> arr = {5, 6, 1, 3};
    recursive_selection_sort(arr, arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}