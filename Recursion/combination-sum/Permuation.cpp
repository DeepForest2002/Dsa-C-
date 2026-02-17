#include <bits/stdc++.h>
using namespace std;

void find_permutation(vector<int> arr, vector<vector<int>> &ans, vector<int> &ds, vector<int> &map)
{
    if (ds.size() == arr.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        // if the element is present in the map or not
        if (map[i] == 0)
        {
            map[i]++;
            ds.push_back(arr[i]);
            find_permutation(arr, ans, ds, map);
            map[i]--;
            ds.pop_back();
        }
    }
}

vector<vector<int>> Permutations(vector<int> arr)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> map(arr.size(), 0);
    find_permutation(arr, ans, ds, map);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans_arr = Permutations(arr);
    for (auto el : ans_arr)
    {
        for (auto el1 : el)
        {
            cout << el1 << " ";
        }
        cout << endl;
    }
    return 0;
}