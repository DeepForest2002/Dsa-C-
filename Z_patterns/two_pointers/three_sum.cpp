// Three sum closest to zero
#include <bits/stdc++.h>
using namespace std;

void find_two_sum(vector<int> &arr, vector<vector<int>> &ans, int sum, int left, int right)
{
    vector<int> res;
    while (left < right)
    {
        int s = arr[left] + arr[right];
        if (sum == s)
        {
            // res.push_back(-1 * sum);
            // res.push_back(arr[left]);
            // res.push_back(arr[right]);
            // ans.push_back(res);
            ans.push_back({-1 * sum, arr[left], arr[right]});
            left++;
            right--;
            while (left < arr.size() && arr[left] == arr[left - 1])
                left++;
            while (right >= 0 && arr[right] == arr[right + 1])
                right--;
        }
        else if (s > sum)
            right--;
        else
            left++;
    }
}

vector<vector<int>> ThreeSum(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int sum = -1 * arr[i];
        int left = i + 1;
        int right = arr.size() - 1;
        find_two_sum(arr, ans, sum, left, right);
    }
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, -1, -4, 1, 2};
    vector<vector<int>> ans = ThreeSum(arr);
    for (auto innerArray : ans)
    {
        for (auto element : innerArray)
        {
            cout << element << " ";
        }
        cout << endl;
    }
    return 0;
}