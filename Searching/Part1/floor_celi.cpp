#include <iostream>
#include <vector>
using namespace std;

int find_floor(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int find_celi(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 33, 45};
    int target = 25;
    int floor = find_floor(arr, target);
    int celi = find_celi(arr, target);
    cout << floor << " " << celi;
    return 0;
}