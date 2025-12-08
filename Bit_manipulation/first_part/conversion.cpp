#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

string find_binary(int val)
{
    string res = "";
    while (val > 0)
    {
        if (val % 2 == 1)
            res += '1';
        else
            res += '0';
        val = val / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int convert_decimal(int val)
{
    int sum = 0;
    int count = 0;
    while (val)
    {
        sum = (val % 10) * pow(2, count) + sum;
        count += 1;
        val = val / 10;
    }
    return sum;
}

int main()
{
    int decimal_value = 13;
    string binary_value = find_binary(decimal_value);
    cout << convert_decimal(111);
    return 0;
}