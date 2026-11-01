#include <bits/stdc++.h>
using namespace std;

int number_of_duplicates(vector<int> arr)
{
    int cm = 0;
    for (int officer = 1; officer < arr.size(); officer++)
    {
        if (arr[cm] != arr[officer])
        {
            arr[cm + 1] = arr[officer];
            cm += 1;
        }
    }
    return cm + 1;
}

int main()
{
    vector<int> arr = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4};
    cout << number_of_duplicates(arr);
    return 0;
}