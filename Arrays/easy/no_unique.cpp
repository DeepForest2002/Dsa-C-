#include <bits/stdc++.h>
using namespace std;

int find_ans(vector<int> arr)
{
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i += 1;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}

int find_ans2(vector<int> arr)
{
    set<int> s;
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    cout << find_ans2(arr);
    return 0;
}