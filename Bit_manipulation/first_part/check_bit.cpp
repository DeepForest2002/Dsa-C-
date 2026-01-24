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

int find_pow()
{
    // find the value of n to the power 6
    int power = 6;
    int base = 3;
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans = ans * base;
        base = base * base;
        power = power >> 1;
    }
    return ans;
}

int main()
{
    int n = 13;
    int i = 2;
    cout << find_pow();
    return 0;
}