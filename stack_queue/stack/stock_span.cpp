#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_ans(vector<int> arr)
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 1;
        while (!st.empty() && st.top() <= arr[i])
        {
            count += 1;
        }
        ans.push_back(count);
        st.push(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    vector<int> ans = find_ans(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}