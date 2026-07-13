// Get the top k frequent elements in an array
#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        // min heap on both
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

vector<int> topKelements(vector<int> &arr, int k)
{
    int n = arr.size();
    // min heap pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    // insert on the min heap with pairs
    for (auto element : mpp)
    {
        int freq = element.second;
        int elem = element.first;
        pair<int, int> pr = {freq, elem};
        if (pq.size() < k)
        {
            pq.push(pr);
            continue;
        }
        if (pr.first > pq.top().first)
        {
            pq.pop();
            pq.push(pr);
        }
        else
            continue;
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{

    vector<int> arr = {2, 1, 2, 4, 1, 2, 3, 3, 1, 3, 3, 4};
    vector<int> ans = topKelements(arr, 2);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    return 0;
}