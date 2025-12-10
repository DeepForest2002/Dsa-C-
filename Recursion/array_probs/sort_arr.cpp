#include <iostream>
#include <vector>
using namespace std;

bool check_arr(vector<int> arr, int n, int i)
{
    if (n == 0 || i == n - 1)
        return true;
    if (arr[i] > arr[i + 1])
        return false;
    return check_arr(arr, n, i += 1);
}

int find_element(vector<int> arr, int target, int n, int i)
{
    if (i > n - 1)
        return -1;
    if (arr[i] == target)
        return i;
    return find_element(arr, target, n, i += 1);
}

int find_sum(vector<int>arr, int n, int i, int sum){
    
}

int main()
{
    vector<int> arr = {1, 4, 3, 0};
    int n = arr.size();
    int i = 0;
    cout << check_arr(arr, n, i) << endl;
    cout << find_element(arr, 9, n, 0);
    return 0;
}