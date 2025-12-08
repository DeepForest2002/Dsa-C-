#include <iostream>
#include <vector>
using namespace std;

// Upper bound is the smallest index where arr[index]>target and lower bound is arr[index]>=target

int find_index(vector<int> &arr, int target, int n)
{
    int index = -1;
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            index = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return index;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 8, 9, 10, 11};
    int target = 9;
    int size = arr.size();

    int index = find_index(arr, target, size);
    cout << index;
    return 0;
}