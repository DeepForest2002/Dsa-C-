#include <iostream>
#include <vector>
using namespace std;

int max_ones(vector<int> arr)
{
    int maxlen = 0;
    int l = 0, r = 0, zeroCount = 0;
    while (r < arr.size())
    {
        if (arr[r] == 0)
            zeroCount += 1;
        while (zeroCount > 1)
        {
            if (arr[l] == 0)
                zeroCount -= 1;
            l += 1;
        }
        maxlen = max(maxlen, (r - l + 1));
        r += 1;
    }
    return maxlen;
}

int main()
{
    vector<int> arr = {0, 1, 0, 1, 1};
    cout << max_ones(arr);
    return 0;
}