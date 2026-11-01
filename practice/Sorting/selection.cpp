#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
    return;
}

int main()
{
    vector<int> arr = {2, 5, 9, 7, 8};
    selection_sort(arr);
    for (auto el : arr)
    {
        cout << el << endl;
    }
    return 0;
}