#include <bits/stdc++.h>
using namespace std;

int search_rotated_sorted(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }

        // left sorted
        if (arr[low] <= arr[mid])
        {
            // check if the element is present in between them
            if (arr[low] <= target && target < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right sorted
        else
        {
            if (arr[mid] < target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {50, 60, 70, 80, 90, 100, 10, 20, 30, 40};
    cout << search_rotated_sorted(arr, 40);
    return 0;
}