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

int longest_substring2(string str)
{
    int l = 0, r = str.length() - 1;
    int maxLen = INT_MIN;
    map<char, int> mpp;
    while (r < str.length())
    {
        mpp[str[r]]++;
        int len = r - l + 1;

        while (mpp.size() < len)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l += 1;
            len = r - l + 1;
        }

        maxLen = max(maxLen, len);
        r += 1;
    }
    return maxLen;
}

int main()
{
    string str = "bbbbb";
    cout << longest_substring2(str);
    return 0;
}