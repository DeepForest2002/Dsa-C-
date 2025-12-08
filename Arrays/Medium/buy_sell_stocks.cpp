#include <iostream>
#include <vector>
using namespace std;

int function(vector<int> &arr, int size)
{
    int maxProfit = 0, mini = arr[0];
    for (int i = 1; i < size; i++)
    {
        int price = arr[i] - mini;
        maxProfit = max(price, maxProfit);
        mini = min(arr[i], mini);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 2, 4, 6, 5};
    int size = arr.size();

    int max_profit = function(arr, size);
    cout << max_profit;
    return 0;
}