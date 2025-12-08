#include <iostream>
#include <vector>
using namespace std;

vector<int> function(vector<int> arr, int size)
{
    // First get the pos and neg elements
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    if (pos.size() < neg.size())
    {
        // at first insert equal number of +ve and -ve elements in the array
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index += 1;
        }
    }
    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index += 1;
        }
    }

    // Time complexity is 0(n) and the space complexity is 0(n)
    //  check if pos is greater than neg or not
    return arr;
}

int main()
{
    vector<int> arr = {1, 2, -4, -5, 3, 4};
    int size = arr.size();
    vector<int> ans = function(arr, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}