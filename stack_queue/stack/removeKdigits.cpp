#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string &ans, int k)
{
    stack<char> st;
    string str = "";
    for (auto ch : str)
    {
        if (st.empty())
        {
            st.push(ch);
            continue;
        }
        else if (!st.empty() && st.top() >= ch && k)
        {
            st.pop();
            k -= 1;
        }
        st.push(ch);
    }
    if (st.empty())
        return "0";
    while (!st.empty())
    {
        str = str + st.top();
        st.pop();
    }
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '0')
            str.pop_back();
        else
            break;
    }
    if (str.length() == 0)
        return "0";
    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string str = "1432219";
    cout << removeKdigits(str, 3);
    return 0;
}