#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> find_leaders(vector<int> arr, int n)
{
    vector<int> ans_arr;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans_arr.push_back(arr[i]);
            maxi = max(arr[i], maxi);
        }
    }
    return ans_arr;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    int size = arr.size();
    vector<int> ans = find_leaders(arr, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}