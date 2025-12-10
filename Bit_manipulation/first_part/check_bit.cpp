#include <iostream>
using namespace std;

bool check_right_shift(int n, int i)
{
    // first right shift the number by i places
    n = n >> i;
    if (n & 1)
        return true;
    else
        return false;
}

bool check_left_shift(int n, int i)
{
    if ((n & (1 << i)) != 0)
        return true;
    else
        return false;
}

int main()
{
    int n = 13;
    int i = 2;
    bool ans = check_left_shift(n, i);
    cout << ans;
    return 0;
}