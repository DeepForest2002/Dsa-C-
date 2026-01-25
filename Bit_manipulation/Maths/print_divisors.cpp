#include <iostream>
#include <cmath>
using namespace std;

void print_divisors(int n)
{
    for (int i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << " ";
        }
    }
}

int main()
{
    int n = 6;
    print_divisors(n);
    return 0;
}