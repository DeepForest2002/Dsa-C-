#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_nge(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (i >= n)
        {
            while (!st.empty() && st.top() <= arr[i % n])
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
    vector<int> arr = {1, 2, 3, 4, 3};
    vector<int> ans = find_nge(arr, arr.size());
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}