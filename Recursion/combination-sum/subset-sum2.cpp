#include <bits/stdc++.h>
using namespace std;

void find_subsetSum(int index, vector<int> &arr, set<int> &ds, int sum)
{
    if (index == arr.size())
    {
        ds.insert(sum);
        return;
    }
    sum += arr[index];
    find_subsetSum(index + 1, arr, ds, sum);
    sum -= arr[index];
    find_subsetSum(index + 1, arr, ds, sum);
}

vector<int> find_subset(vector<int> &arr)
{
    set<int> ds;
    find_subsetSum(0, arr, ds, 0);
    // sort(ds.begin(), ds.end());
    vector<int> ans(ds.begin(), ds.end());
    return ans;
}

int main()
{
    vector<int> ans = {1, 2, 2};
    vector<int> ans_arr = find_subset(ans);
    for (int i = 0; i < ans_arr.size(); i++)
    {
        cout << ans_arr[i] << "";
    }
    return 0;
}