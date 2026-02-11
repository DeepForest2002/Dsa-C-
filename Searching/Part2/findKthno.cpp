#include <iostream>
#include <vector>
using namespace std;

int find_missing_number(vector<int> arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing_no = arr[mid] - (mid + 1);
        if (missing_no > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return high + k + 1;
}

int main()
{
    vector<int> arr = {4, 7, 9, 10};
    cout << find_missing_number(arr, 1);
    return 0;
}