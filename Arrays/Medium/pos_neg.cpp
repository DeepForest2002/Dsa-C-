#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int> &arr, int size)
{
    vector<int> neg;
    vector<int> pos;

    // Store the negative and positive elements
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    // Now we have all the negative and pos elements
    for (int i = 0; i < size / 2; i++)
    {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
}

// This code is for optimal approach
vector<int> Optimal_approach(vector<int> arr, int size)
{
    // Empty array of size n initializing every element with 0
    vector<int> ans_arr(size, 0);
    int posIndex = 0;
    int negIndex = 1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            ans_arr[negIndex] = arr[i];
            negIndex += 2;
        }
        else
        {
            ans_arr[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    return ans_arr;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    int size = arr.size();
    // rearrange(arr, size);
    vector<int> ans = Optimal_approach(arr, size);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}