#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    // merge(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {38, 27, 43, 10};
    mergeSort(arr, 0, arr.size() - 1);
    return 0;
}