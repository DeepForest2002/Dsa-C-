#include <bits/stdc++.h>
using namespace std;

void PrintSub(int index, vector<int> arr, vector<int> &ds, int n, int sum, int &s, int &count)
{
    if (index == n)
    {
        if (s == sum)
        {
            count += 1;
        }
        return;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    PrintSub(index + 1, arr, ds, n, sum, s, count);
    s -= arr[index];
    ds.pop_back();
    PrintSub(index + 1, arr, ds, n, sum, s, count);
}

// print only one element
bool PrintSum2(int index, vector<int> arr, vector<int> &ds, int n, int sum, int &s)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto el : ds)
                cout << el << " ";
            return true;
        }
        else
            return false;
    }
    ds.push_back(arr[index]);
    s += arr[index];
    if (PrintSum2(index + 1, arr, ds, n, sum, s))
        return true;
    s -= arr[index];
    ds.pop_back();
    if (PrintSum2(index + 1, arr, ds, n, sum, s))
        return true;
    return false;
}

void print_all_subseq(vector<int> arr, vector<int> &ds, vector<vector<int>> &ans, int index, int n)
{
    if (index == n)
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(arr[index]);
    print_all_subseq(arr, ds, ans, index + 1, n);
    ds.pop_back();
    print_all_subseq(arr, ds, ans, index + 1, n);
}

int main()
{
    vector<int> arr = {1, 2, 1};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    int s = 0, count = 0;
    vector<vector<int>> ans;
    print_all_subseq(arr, ds, ans, 0, n);
    string str = "123";
    int num = stoi(str);
    cout << num << endl;
    return 0;
}