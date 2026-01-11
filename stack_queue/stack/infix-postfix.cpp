#include <iostream>
#include <string>
#include <stack>
using namespace std;

int Priority(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string Convert_postfix(string str)
{
    int i = 0;
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
                while (!st.empty() && Priority(str[i]) <= Priority(st.top()) && st.top() != '(')
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
    return ans;
}

int main()
{
    // i have to convert this into postfix form
    string str = "a+b*(c^d-e)";
    cout << Convert_postfix(str);
    return 0;
}