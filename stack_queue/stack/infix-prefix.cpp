// steps to follow - first reverse the string , 2. convert from infix to postfix 3. reverse the ans and return it

#include <bits/stdc++.h>
using namespace std;

string reverse_string(string str)
{
    reverse(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
    return str;
}

int Priority(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

string Convert_Prefix(string str)
{
    int i = 0;
    str = reverse_string(str);
    string ans = "";
    stack<char> st;
    while (i < str.length())
    {
        // check if it is an operand or not
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            ans = ans + str[i];
        }
        else
        {
            if (str[i] == '(')
            {
                st.push(str[i]);
            }
            else if (str[i] == ')')
            {
                // pop the stack until the stack top is not (
                while (st.top() != '(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            // encounter with operators
            else
            {
                while (!st.empty() && Priority(str[i]) < Priority(st.top()) && st.top() != '(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        i += 1;
    }
    // at the end of the while loop
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return reverse_string(ans);
}

int main()
{
    string str = "(A+B)*C-D+F";
    cout << Convert_Prefix(str);
    return 0;
}