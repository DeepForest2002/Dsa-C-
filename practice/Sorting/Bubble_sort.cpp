#include <bits/stdc++.h>
using namespace std;

void bubble(vector<int> &arr)
{
    int n = arr.size();
    for (int i = n - 1; i >= 0;i--){
        int didSwap = 0;
        for (int j = 0; j < i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j + 1]);
            didSwap = 1;
        }
        if(didSwap==0) break;
    }
}

int main()
{
    vector<int> arr = {2, 5, 9, 7, 8};
    bubble(arr);
    for (auto el : arr)
    {
        cout << el << endl;
    }
    return 0;
}