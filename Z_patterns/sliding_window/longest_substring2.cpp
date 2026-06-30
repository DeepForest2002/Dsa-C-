#include <bits/stdc++.h>
using namespace std;

int longest_substring(string str)
{
    int l = 0, r = 0, maxLen = INT_MIN;
    unordered_map<char, int> mpp;
    while (r < str.length())
    {
        if (mpp.find(str[r]) != mpp.end())
        {
            if (l <= mpp[str[r]])
                l = mpp[str[r]] + 1;
        }
        mpp[str[r]]++;
        maxLen = max(maxLen, (r - l + 1));
        r += 1;
    }
    return maxLen == INT_MIN ? 0 : maxLen;
}

int main()
{
    string str = "abcabcbb";
    cout << longest_substring(str);
    return 0;
}