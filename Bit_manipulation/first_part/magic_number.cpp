#include <iostream>
#include <math.h>
using namespace std;

int magic_number(int n)
{
    int power = 5;
    int sum = 0;
    while (n > 0)
    {
        if (n & 1)
            sum += power;

        power *= 5;
        n = n >> 1;
    }
    return sum;
}

int find_digits()
{
    int num = 10;
    int base = 2;

    int ans = int(log(num) / log(base)) + 1;
    return ans;
}

int main()
{
    int n = 6;
    cout << magic_number(n) << endl;
    cout << find_digits();
    return 0;
}