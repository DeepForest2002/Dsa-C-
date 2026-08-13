#include <bits/stdc++.h>
using namespace std;

void func(string digits, int idx, int n, string &str, vector<string> &ans, unordered_map<char, string> f)
{
    if (idx == n)
    {
        ans.push_back(str);
        return;
    }
    string s = f[digits[idx]];
    for (int i = 0; i < s.length(); i++)
    {
        str.push_back(s[i]);
        func(digits, idx + 1, n, str, ans, f);
        str.pop_back();
    }
    return;
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> f;
    f['2'] = "abc";
    f['3'] = "def",
    f['4'] = "ghi",
    f['5'] = "jkl",
    f['6'] = "mno",
    f['7'] = "pqrs",
    f['8'] = "tuv",
    f['9'] = "wxyz";
    vector<string> ans;
    string str = "";
    func(digits, 0, digits.size(), str, ans, f);
    return ans;
}
int main()
{
    vector<string> ans = letterCombinations("23");
    for (string ele : ans)
    {
        cout << ele << ",";
    }
    return 0;
}