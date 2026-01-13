// this problem is about next smaller element on the left
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> find_smaller(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
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
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = find_smaller(arr, arr.size());
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}