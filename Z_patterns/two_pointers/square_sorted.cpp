#include <bits/stdc++.h>
using namespace std;

void square(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = arr[i] * arr[i];
    }
}

void merge(vector<int> &res, vector<int> &narr, vector<int> &parr)
{
    int i = 0, j = 0;
    while (i < narr.size() && j < parr.size())
    {
        if (narr[i] <= parr[j])
        {
            res.push_back(narr[i++]);
        }
        else
            res.push_back(parr[j++]);
    }
    while (i < narr.size())
        res.push_back(narr[i++]);
    while (j < parr.size())
        res.push_back(parr[j++]);
}

vector<int> square_sorted_arry(vector<int> arr)
{
    vector<int> narr;
    vector<int> parr;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            narr.push_back(arr[i]);
        else
            parr.push_back(arr[i]);
    }

    if (narr.size() > 0)
    {
        square(narr);
        reverse(narr.begin(), narr.end());
    }
    if (parr.size() > 0)
        square(parr);

    if (narr.size() < 0)
        return parr;
    if (parr.size() < 0)
        return parr;

    merge(res, narr, parr);
    return res;
}

int main()
{
    vector<int> arr = {-4, -1, 0, 3, 10};

    return 0;
}