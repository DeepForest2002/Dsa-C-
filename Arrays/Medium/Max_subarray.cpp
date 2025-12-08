// Find the maximum subarray sum using kadnaes algorithm
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int Kadnaes_algo(vector<int> &arr, int size)
{
    int sum = 0, maxi = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
            sum = 0;
    }
    if (maxi < 0)
    {
        maxi = 0;
    }
    return maxi;
}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = arr.size();

    int ans = Kadnaes_algo(arr, size);
    cout << ans;
    return 0;
}