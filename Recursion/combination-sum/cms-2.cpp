
#include <bits/stdc++.h>
using namespace std;

void find_combinations(int index, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    // i am picking element from current index to n-1;
    for (int i = index; i < arr.size(); i++)
    {
        if (arr[i] > target)
            break;
        if (i > index && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        find_combinations(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> find_ans(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(), arr.end());
    find_combinations(0, target, arr, ans, ds);
    return ans;
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