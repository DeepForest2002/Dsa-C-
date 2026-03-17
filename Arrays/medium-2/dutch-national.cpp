#include <iostream>
#include <vector>
using namespace std;

void sort_arr(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid += 1;
            low += 1;
        }
        else if (arr[mid] == 1)
            mid += 1;
        else
        {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }
}

int main()
{
    vector<int> arr = {1, 0, 2, 1, 0};
    sort_arr(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
    return 0;
}