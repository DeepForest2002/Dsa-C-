#include <iostream>
#include <vector>
using namespace std;

int Binary_search(vector<int> arr, int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    if (arr[mid] > target)
    {
        return Binary_search(arr, low, mid - 1, target);
    }
    else
    {
        return Binary_search(arr, mid + 1, high, target);
    }
}

int main()
{
    vector<int> arr = {1, 5, 9, 11, 15, 17};
    int size = arr.size();
    int i = 0, j = size - 1;
    int mid = (i + j) / 2;
    int target = 17;
    int ans = Binary_search(arr, i, j, target);
    cout << ans;
    return 0;
}