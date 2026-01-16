#include <bits/stdc++.h>
using namespace std;

stack<int> asteroid_collision(vector<int> arr)
{
    stack<int> st;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > 0)
            st.push(arr[i]);
        else
        {
            while (!st.empty() && abs(arr[i]) > st.top() && st.top() > 0)
            {
                st.pop();
            }
            if (st.top() == abs(arr[i]))
            {
                st.pop();
                continue;
            }
            if (st.empty() && st.top() < 0)
                st.push(arr[i]);
        }
    }

    return st;
}

int main()
{
    vector<int> arr = {3, 5, -6, 2, -1, 4};
    stack<int> st = asteroid_collision(arr);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}