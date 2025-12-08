#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> next_perm(vector<int> &arr)
{
    int n = arr.size();
    int index = -1;

    // The first possible break index is n-2 so we will start from that index and try to find the break index
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    // if no index found return the reversed array
    if (index == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    // second step
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[index], arr[i]);
            break;
        }
    }

    // third step reverse the remaining part and return the array
    reverse(arr.begin() + index + 1, arr.end());
    return arr;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};

    arr = next_perm(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}