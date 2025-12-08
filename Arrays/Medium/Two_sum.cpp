#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

string Two_sum(vector<int> arr, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        int more = target - arr[i];
        if (mpp.find(more) != mpp.end())
        {
            return "Yes";
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }
    return "no";
}

// Optimal Solution
string Two_sum_optimal(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else if (arr[i] + arr[j] > target)
        {
            j--;
        }
        else
        {
            return "yes";
        }
    }
    return "no";
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 15;
    string ans = Two_sum_optimal(arr, target);
    cout << ans;
    return 0;
}