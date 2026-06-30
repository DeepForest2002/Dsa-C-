#include <bits/stdc++.h>
using namespace std;

int fruit_in_the_basket(vector<int> &arr)
{
    unordered_map<char, int> mpp;
    int l = 0, r = 0, maxLen = INT_MIN;
    while (r < arr.size())
    {
        mpp[arr[r]]++;
        while (mpp.size() > 2)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
            l += 1;
        }
        maxLen = max(maxLen, (r - l + 1));
        r += 1;
    }
    return maxLen == INT_MIN ? -1 : maxLen;
}

int main()
{
    vector<int> arr = {0, 1, 2, 2, 2};
    cout << fruit_in_the_basket(arr);
    return 0;
}