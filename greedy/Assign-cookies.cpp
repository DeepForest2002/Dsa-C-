#include <bits/stdc++.h>
using namespace std;

int Assign_cookies(vector<int> g, vector<int> s)
{
    int m = g.size();
    int n = s.size();
    int l = 0, r = 0;
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    while (l < n)
    {
        if (g[r] <= s[l])
            r += 1;
        l += 1;
    }
    return r;
}

int main()
{

    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};
    cout << Assign_cookies(g, s);
    return 0;
}