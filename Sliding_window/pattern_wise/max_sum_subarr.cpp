#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int> &arr, int k)
{
    // k is the fixed length
    map<int, int> mpp;
    int left = 0, right = 0;
    int sum = 0;
    int max_sum = 0;
    while (right < arr.size() - 1)
    {
        if (right - left == k)
        {
            if (sum > max_sum)
                max_sum = sum;
            sum = sum - arr[left];
            left++;
        }
        sum += arr[right];
        right += 1;
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {1, 0, 3, 5, 2, 1, 4};
    cout << max_sum(arr, 3);
    return 0;
}