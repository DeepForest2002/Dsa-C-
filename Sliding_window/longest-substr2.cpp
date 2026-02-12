#include <bits/stdc++.h>
using namespace std;

int longest_substring(string str, int k)
{
    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mpp;
    while (r < str.length())
    {
        mpp[str[r]]++;
        while (mpp.size() > k)
        {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0)
                mpp.erase(str[l]);
            l += 1;
        }
        if (mpp.size() <= k)
            maxlen = max(maxlen, (r - l + 1));
        r += 1;
    }
    return maxlen;
}

int main()
{
    string str = "aaabbccd";
    cout << longest_substring(str, 3);
    return 0;
}