#include <bits/stdc++.h>
using namespace std;

string two_sum(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
            return "YES";
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }
    return "NO";
}

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    cout << two_sum(arr, 14);
    return 0;
}