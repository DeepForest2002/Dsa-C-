
#include <bits/stdc++.h>
using namespace std;

void find_combinations(int index, int target, vector<int> &arr, set<vector<int>> &ans, vector<int> &ds)
{
    if (index == arr.size())
    {
        if (target == 0)
        {
            ans.insert(ds);
        }
        return;
    }
    // pick and not pick
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        find_combinations(index, target - arr[index], arr, ans, ds);
        ds.pop_back();
    }
    find_combinations(index + 1, target - arr[index], arr, ans, ds);
}

vector<vector<int>> find_ans(vector<int> arr, int target)
{
    set<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    find_combinations(0, target, arr, ans, ds);
    vector<vector<int>> st(ans.begin(), ans.end());
    return st;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 4;
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