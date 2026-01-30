#include <bits/stdc++.h>
using namespace std;

int fruit_in_basket(vector<int> &arr, int buckets)
{
    int l = 0, r = 0;
    int maxlen = 0;
    unordered_map<int, int> mpp;

    while (r < arr.size())
    {
        // Expand window
        mpp[arr[r]]++;

        // Shrink window if distinct fruits exceed bucket limit
        while (mpp.size() > buckets)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
            {
                mpp.erase(arr[l]);
            }
            l++;
        }

        // Update maximum length of valid window
        int len = r - l + 1;
        if (len > maxlen)
            maxlen = len;

        r++;
    }

    return maxlen;
}

int main()
{
    vector<int> arr = {
        1,
        2,
        3,
        2,
        2,
    };
    cout << fruit_in_basket(arr, 2);
    return 0;
}