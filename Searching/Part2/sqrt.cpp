#include <iostream>
using namespace std;

int findf_ans(int num)
{
    int low = 0;
    int high = num;
    while (low <= high)
    {
        int mid = low + high / 2;
        long long mul = mid * mid;
        if (mul == num)
            return mid;
        else if (mul > num)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int num = 36;
    cout << findf_ans(num);
    return 0;
}