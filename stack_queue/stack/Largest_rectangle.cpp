#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_psl(vector<int> &arr)
{
    vector<int> psl(arr.size());
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
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
vector<int> find_nsl(vector<int> arr)
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

int find_rectangle(vector<int> &psl, vector<int> &nsl, vector<int> arr)
{
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i] * abs(nsl[i] - psl[i] - 1));
    }
    return maxi;
}

void print(vector<int> arr)
{
    for (auto el : arr)
    {
        cout << el << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    vector<int> psl = find_psl(arr);
    vector<int> nsl = find_nsl(arr);
    cout << find_rectangle(psl, nsl, arr);
    return 0;
}