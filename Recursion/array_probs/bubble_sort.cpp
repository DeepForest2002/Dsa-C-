#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr, int n)
{
    bool swapping = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapping = true;
            }
        }
        if (swapping == false)
            break;
    }
    return;
}

void recursive_bubble_sort(vector<int> &arr, int n, int i)
{
    if (i >= n - 1)
        return;
    bool swapping = true;
    for (int j = 0; j < n - 1 - i; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            swapping = true;
        }
    }
    if (swapping == false)
        return;
    else
        recursive_bubble_sort(arr, n, i += 1);
}

int main()
{
    vector<int> arr = {5, 6, 1, 3};
    recursive_bubble_sort(arr, arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}