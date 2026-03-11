#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_ans(vector<int> arr)
{
    int largest = INT_MIN, sec_largest = INT_MIN;
    int smallest = INT_MAX, sec_smallest = INT_MAX;

    // largest and smallest element in the arr
    for (int i = 0; i < arr.size(); i++)
    {
        largest = max(largest, arr[i]);
        smallest = min(smallest, arr[i]);
    }

    // second largest and second smallest
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > sec_largest && arr[i] != largest)
            sec_largest = arr[i];
        if (arr[i] < sec_smallest && arr[i] != smallest)
            sec_smallest = arr[i];
    }
    pair<int, int> p;
    p.first = sec_largest;
    p.second = sec_smallest;
    return p;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    pair<int, int> p = find_ans(arr);
    cout << p.first << " " << p.second << endl;
    return 0;
}