#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int s = low;
    int e = high;
    int mid = s + (e - s) / 2;
    int pivot = arr[mid];
    while (s <= e)
    {
        while (arr[s] < pivot)
        {
            s += 1;
        }

        while (arr[e] > pivot)
        {
            e -= 1;
        }
        if (s <= e)
        {
            swap(arr[s], arr[e]);
            s += 1;
            e -= 1;
        }
    }
    QuickSort(arr, low, e);
    QuickSort(arr, s, high);
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    QuickSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}