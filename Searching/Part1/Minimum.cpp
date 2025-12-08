#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;

int search(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int lowest = INT_MAX;

    while(low<=high){
        int mid = low + (high - low) / 2;

        if(arr[low]<=arr[mid]){
            //find the min element in left poriton
            
        }
    }
}

int main()
{

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int index = search(arr);

    return 0;
}