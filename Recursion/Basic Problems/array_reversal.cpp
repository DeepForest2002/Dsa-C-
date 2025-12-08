#include <iostream>
using namespace std;

// This is called iterative function
void reversal(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left = left + 1;
        right -= 1;
    }
    return;
}

// Now recursive function
void recursive_reverse(int arr[], int left, int right)
{
    if (left > right)
        return;
    swap(arr[left++], arr[right--]);
    recursive_reverse(arr, left, right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    // cout << size << endl;

    recursive_reverse(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}