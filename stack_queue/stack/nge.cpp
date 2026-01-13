#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nge(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
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
    return ans;
}

int main()
{
    vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> ans = nge(arr, arr.size());
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}