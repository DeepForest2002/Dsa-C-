#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int> &arr, int k)
{
    priority_queue<int> pq;
    int i = 0;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (arr[i] >= pq.top())
            continue;
        else
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    
    return 0;
}