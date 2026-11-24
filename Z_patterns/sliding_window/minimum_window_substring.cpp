#include <bits/stdc++.h>
using namespace std;

bool is_equal(vector<int> &have, vector<int> &need)
{
    for (int i = 0; i < 128; i++)
    {
        if (have[i] < need[i])
            return false;
    }
    return true;
}
string minWindow(string s, string t)
{
    vector<int> need(128, 0);
    vector<int> have(128, 0);
    for (int i = 0; i < t.length(); i++)
    {
        need[t[i]]++;
    }
    int l = 0, r = 0, res = INT_MAX, start = 0;
    while (r < s.length())
    {
        have[s[r]]++;
        while (is_equal(have, need))
        {
            have[s[l]]--;
            if (r - l + 1 < res)
            {
                res = r - l + 1;
                start = l;
            }
            l += 1;
        }
        r += 1;
    }
    return res == INT_MAX ? "" : s.substr(start, res);
}
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    return 0;
}