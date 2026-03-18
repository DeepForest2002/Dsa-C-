#include <bits/stdc++.h>
using namespace std;
vector<int> nge(vector<int> arr)
{
    stack<int> st;
    vector<int> ans(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i] >= st.top())
        {
            st.pop();
        }
        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = nge(arr);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}