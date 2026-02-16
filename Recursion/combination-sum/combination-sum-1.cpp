#include <bits/stdc++.h>
using namespace std;

void find_combinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (target >= arr[index])
    {
        ds.push_back(arr[index]);
        find_combinations(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }
    find_combinations(index + 1, target, arr, ans, ds);
}

vector<vector<int>> find_ans(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    find_combinations(0, target, arr, ans, ds);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = find_ans(arr, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}