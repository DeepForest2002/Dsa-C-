#include <bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= arr[i])
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
    vector<int> arr = {4, 8, 5, 2, 25};
    vector<int> ans = nse(arr);
    for (auto el : ans)
    {
        cout << el << "";
    }
    int arr1[] = {4, 8, 5, 2, 25};
    int maxi = *max_element(arr1.begin(), arr1.end());
    return 0;
}