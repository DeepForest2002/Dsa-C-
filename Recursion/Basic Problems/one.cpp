#include <bits/stdc++.h>
using namespace std;

void print(int count)
{
    if (count == 0)
        return;
    cout << "Sayan Pramanik" << endl;
    count = count - 1;
    print(count);
}

// print 1 to n using recursion
void function1(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    function1(i + 1, n);
}

void function2(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    function2(n - 1);
}

int sum_n_numbers(int sum, int n)
{
    if (n == 0)
        return sum;
    sum = sum + n;
    return sum_n_numbers(sum, n = n - 1);
}

// Factorial of n numbers (5! = 5*4*3*2*1)
int factorial(int res, int n)
{
    if (n == 0)
        return res;
    res = res * n;
    return factorial(res, n = n - 1);
}

// Reverse an array using recursion

int main()
{

    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;
    // function1(1, n);
    // function2(n);
    // cout << sum_n_numbers(0, n) << endl;
    cout << factorial(1, n) << endl;
    return 0;
}
