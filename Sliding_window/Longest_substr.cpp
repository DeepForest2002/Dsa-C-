#include <bits/stdc++.h>
using namespace std;

int find_len(string str)
{
    int l = 0;
    int r = 0;
    int maxlen = 0;
    unordered_map<char, int> mpp;
    while (r < str.length())
    {
        if (mpp.find(str[r]) != mpp.end())
        {
            if (mpp[str[r]] >= l)                               
            {
                l = mpp[str[r]] + 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
            }
        }
        maxlen = max(maxlen, (r - l + 1));
        mpp[str[r]] = r;
        r += 1;
    }
    return maxlen;
}

int main()
{
    string str = "cabdzabcd";
    cout << find_len(str);
    return 0;
}