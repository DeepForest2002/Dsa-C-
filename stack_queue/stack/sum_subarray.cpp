#include <bits/stdc++.h>
using namespace std;

vector<int> find_psl(const vector<int> arr)
{
    vector<int> psl(arr.size());
    stack<int> st;

    // to find psl we have to start from the left side
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (st.empty())
            psl[i] = -1;
        else
            psl[i] = st.top();
        st.push(i);
    }

    return psl;
}

vector<int> find_nsl(const vector<int> &arr)
{
    vector<int> nsl(arr.size());
    stack<int> st;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            nsl[i] = arr.size();
        else
            nsl[i] = st.top();
        st.push(i);
    }

    return nsl;
}

int find_ans(vector<int> arr, vector<int> psl, vector<int> nsl)
{
    int sum = 0;
    int intersect = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        intersect = abs((i - psl[i]) * (nsl[i] - i));
        sum = sum + (intersect * arr[i]);
    }
    return sum;
}

int main()
{
    vector<int> arr = {71, 55, 82, 55};
    vector<int> psl = find_psl(arr);
    vector<int> nsl = find_nsl(arr);

    int ans = find_ans(arr, psl, nsl);
    cout << ans;
    return 0;
}