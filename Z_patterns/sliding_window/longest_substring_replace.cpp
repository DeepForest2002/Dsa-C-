#include <bits/stdc++.h>
using namespace std;

int longest_substring(string s, int k)
{
    vector<int> Hash(26, 0);
    int l = 0, r = 0;
    int maxlen = INT_MIN;
    while (r < s.length())
    {
        Hash[s[r] - 'A']++;
        int len = r - l + 1;
        int freq = *max_element(Hash.begin(), Hash.end());
        int diff = len - freq;
        while (diff > k)
        {
            Hash[s[l] - 'A']--;
            l += 1;
            len = r - l + 1;
            freq = *max_element(Hash.begin(), Hash.end());
            diff = len - freq;
        }
        maxlen = max(maxlen, (r - l + 1));
        r += 1;
    }
    return maxlen;
}

int main()
{
    string str = "AABABBA";
    cout << longest_substring(str, 1);
    return 0;
}