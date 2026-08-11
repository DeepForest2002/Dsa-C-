#include <bits/stdc++.h>
using namespace std;

void generate_paranthesis(int open, int close, int n, vector<string> &ans, string &str)
{
    if (open == n && close == n)
    {
        ans.push_back(str);
        return;
    }
    // open
    if (open < n)
    {
        str.push_back('(');
        generate_paranthesis(open + 1, close, n, ans, str);
        str.pop_back();
    }
    if (close < open)
    {
        str.push_back(')');
        generate_paranthesis(open, close + 1, n, ans, str);
        str.pop_back();
    }
    return;
}

int main()
{
    vector<string> ans;
    string str = "";
    generate_paranthesis(0, 0, 2, ans, str);
    for (auto el : ans)
    {
        cout << el << endl;
    }
    return 0;
}