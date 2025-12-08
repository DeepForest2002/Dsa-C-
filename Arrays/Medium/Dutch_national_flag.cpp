#include <iostream>
#include <vector>
using namespace std;

// Optimal solution -(Dutch National Flag Algorithm)
void sort_arr(vector<int> &arr, int size)
{
    int low = 0, mid = 0, high = size - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            mid += 1;
            low += 1;
        }
        else if (arr[mid] == 1)
        {
            mid += 1;
        }
        else
        {
            // condition is if arr[mid]==2
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }
}

int main()
{

    // we have to sort 0,1,and 2's without using any kind of sorting algo
    vector<int> ans = {1, 2, 0, 2, 1, 0, 0, 1, 1, 2, 0};
    int size = ans.size();

    sort_arr(ans, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}