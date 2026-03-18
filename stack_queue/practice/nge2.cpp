#include <bits/stdc++.h>
using namespace std;

vector<int> nge2(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (i >= n)
        {
            while (!st.empty() && arr[i % n] >= st.top())
            {
                st.pop();
            }
            st.push(arr[i % n]);
        }
        else
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 7, 1, 7, 6, 0};
    vector<int> ans = nge2(arr);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}