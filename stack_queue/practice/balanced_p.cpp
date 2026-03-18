#include <bits/stdc++.h>
using namespace std;

bool check_balanced(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            st.push(str[i]);
        else
        {
            if (st.empty())
                return false;
            char ch = st.top();
            st.pop();
            if ((str[i] == ')' && ch == '(') || (str[i] == '}' && ch == '{') || str[i] == ']' && ch == '[')
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string str = "(()";
    cout << check_balanced(str);
    return 0;
}