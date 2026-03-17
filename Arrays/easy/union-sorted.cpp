#include <bits/stdc++.h>
using namespace std;

vector<int> union_arr(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            if (ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i += 1;
        }
        else if (arr1[j] < arr2[i])
        {
            if (ans.empty() || ans.back() != arr2[j])
                ans.push_back(arr2[j]);
            j += 1;
        }
        else
        {
            if (ans.empty() || ans.back() != arr1[i])
                ans.push_back(arr1[i]);
            i += 1;
            j += 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5};
    vector<int> ans = union_arr(arr1, arr2);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}