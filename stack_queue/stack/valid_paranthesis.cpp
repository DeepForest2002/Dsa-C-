#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check_paran(string str)
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
            if ((str[i] == ')' && ch == '(') || (str[i] == '}' && ch == '{') || (str[i] == ']' && ch == '['))
                continue;
            else
                return false;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string str = "(()";
    bool ans = check_paran(str);
    cout << ans;
    return 0;
}