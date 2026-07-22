#include <bits/stdc++.h>
using namespace std;

void find_combinations(int index, int n, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (index == n)
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        find_combinations(index, n, target - arr[index], arr, ds, ans);
        ds.pop_back();
    }
    find_combinations(index + 1, n, target, arr, ds, ans);
}

vector<vector<int>> find_combination(vector<int> &arr, int target, int n)
{
    vector<int> ds;
    vector<vector<int>> ans;
    find_combinations(0, n, target, arr, ds, ans);
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int n = arr.size();
    vector<vector<int>> ans = find_combination(arr, 7, n);
    for (auto element : ans)
    {
        for (auto el : element)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}