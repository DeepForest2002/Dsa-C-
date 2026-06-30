#include <bits/stdc++.h>
using namespace std;

void find_psi(vector<int> &arr, vector<int> &psi, int n)
{
    stack<int> st;
    // find previous smaller index if the stack is empty then put -1
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        if (st.empty())
            psi[i] = -1;
        else
            psi[i] = st.top();
        st.push(i);
    }
}

void find_nsi(vector<int> &arr, vector<int> nsi, int n)
{
    stack<int> st;
    // find next smaller index if the stack is empty then put -1
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            nsi[i] = n;
        else
            nsi[i] = st.top();
        st.push(i);
    }
}

int subArrMin(vector<int> &arr)
{
    int n = arr.size();
    vector<int> psi(n);
    vector<int> nsi(n);
    find_psi(arr, psi, n);
    find_nsi(arr, nsi, n);
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int intersect = abs((i - psi[i] * (nsi[i] - i)));
        sum += intersect * arr[i];
    }
    return sum;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    cout << subArrMin(arr);

    return 0;
}