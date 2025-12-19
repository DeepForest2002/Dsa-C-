#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> l1(n1), l2(n2);

    // copy these elements
    for (int i = 0; i < n1; i++)
    {
        l1[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++)
    {
        l2[i] = arr[mid + 1 + i];
    }

    int j1 = 0, j2 = 0;
    int k = low;
    while (j1 < n1 && j2 < n2)
    {
        if (l1[j1] < l2[j2])
        {
            arr[k] = l1[j1];
            k += 1;
            j1 += 1;
        }
        else
        {
            arr[k] = l2[j2];
            k += 1;
            j2 += 1;
        }
    }
    while (j1 < n1)
    {
        arr[k] = l1[j1];
        k += 1;
        j1 += 1;
    }
    while (j2 < n2)
    {
        arr[k] = l2[j2];
        k += 1;
        j2 += 1;
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = {8, 3, 4, 12, 5, 6};
    mergeSort(arr, 0, arr.size() - 1);
    print(arr);
    return 0;
}