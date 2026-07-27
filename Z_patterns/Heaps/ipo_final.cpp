#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int w, vector<int> profits, vector<int> capitals)
{
    vector<pair<int, int>> arr;
    int index = 0;
    priority_queue<int> pq;
    for (int i = 0; i < profits.size(); i++)
    {
        arr.push_back({capitals[i], profits[i]});
    }
    sort(arr.begin(), arr.end());
    while (k--)
    {
        while (index < arr.size())
        {
            if (arr[index].first > w)
                break;
            pq.push(arr[index].second);
            index += 1;
        }
        if (pq.empty())
            return w;
        w += pq.top();
        pq.pop();
    }
    return w;
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