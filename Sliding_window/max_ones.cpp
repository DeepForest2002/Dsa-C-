#include <bits/stdc++.h>
using namespace std;

int find_length(vector<int> &arr, int k)
{
    int l = 0, r = 0, zeroCount = 0;
    int maxlen = 0;
    while (r < arr.size())
    {
        if (arr[r] == 0)
            zeroCount += 1;
        while (zeroCount > k)
        {
            if (arr[l] == 0)
                zeroCount -= 1;
            l += 1;
        }
        if (zeroCount <= k)
            maxlen = max(maxlen, (r - l + 1));
        r += 1;
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << find_length(arr, 2);
    return 0;
}