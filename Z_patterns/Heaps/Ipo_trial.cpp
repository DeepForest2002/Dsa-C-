#include <bits/stdc++.h>
using namespace std;

int find_max_index(vector<int> &capital, int target)
{
    int low = 0, high = capital.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (capital[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int findMaximizedCapital(int k, int &w, vector<int> &profits, vector<int> &capital)
{
    sort(profits.begin(), profits.end());
    sort(capital.begin(), capital.end());
    int profit = w;
    int index = 0;
    while (k && index < profits.size())
    {
        int max_cap_index = find_max_index(capital, profit);
        if (max_cap_index == -1)
            break;
        profit = profit + profits[max_cap_index];
        index = max_cap_index;
        k -= 1;
    }
    return profit;
}

int main()
{
    vector<int> profit = {1, 2, 3};
    vector<int> capital = {0, 1, 2};
    int k = 10;
    int w = 0;
    cout << findMaximizedCapital(k, w, profit, capital);
    return 0;
}