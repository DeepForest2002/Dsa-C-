#include <bits/stdc++.h>
using namespace std;

int longestKsubstr(string str, int k)
{
    int l = 0, r = 0, maxLen = INT_MIN;
    unordered_map<char, int> mpp;
    while (r < str.length())
    {
        mpp[str[r]]++;

        // shrink the window until the condition is wrong
        while (mpp.size() > k)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l += 1;
        }
        // while the condition is right calculate the length
        if (mpp.size() == k)
            maxLen = (maxLen, (r - l + 1));
        r += 1;
    }
    return maxLen == INT_MIN ? -1 : maxLen;
}

int main()
{
    string str = "aabacbebebe";
    cout << longestKsubstr(str, 3);
    return 0;
}