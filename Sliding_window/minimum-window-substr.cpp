#include <bits/stdc++.h>
using namespace std;

string minWindow(string str1, string str2)
{
    unordered_map<char, int> need, window;
    int l = 0, r = 0, have = 0, minlen = INT_MAX, start = 0;
    // update the freq in need map
    for (auto el : str2)
    {
        need[el]++;
    }
    int required = need.size();

    for (; r < str1.length(); r++)
    {
        char ch = str1[r];
        window[ch]++;
        if (need.count(ch) && need[ch] == window[ch])
            have += 1;
        while (have == required)
        {
            if ((r - l + 1) < minlen)
            {
                minlen = r - l + 1;
                start = l;
            }
            // shrink the window
            window[str1[l]]--;
            // condition for updating have
            if (need.count(str1[l]) && window[str1[l]] < need[str1[l]])
                have -= 1;
            l += 1;
        }
    }
    return minlen == INT_MAX ? "" : str1.substr(start, minlen);
}

int main()
{
    string str1 = "ADOBECODEBANC";
    string str2 = "ABC";
    cout << minWindow(str1, str2);
    return 0;
}