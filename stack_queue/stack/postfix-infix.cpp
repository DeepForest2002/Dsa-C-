#include <bits/stdc++.h>
using namespace std;

string Conversion(string &str)
{
    stack<string> st;

    for (int i = 0; i < str.size(); i++)
    {
        // If operand, push as string
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            st.push(string(1, str[i]));
        }
        else
        {
            // Operator found
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            // Build "(operand2 operator operand1)"
            string expr = "(" + top2 + str[i] + top1 + ")";
            st.push(expr);
        }
    }

    return st.top();
}
int main()
{
    string str = "AB-DE+FX/";
    cout << Conversion(str);
    return 0;
}