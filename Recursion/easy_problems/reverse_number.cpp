#include <iostream>
using namespace std;

int sum = 0;

int find_ans(int number)
{
    if (number == 0)
        return sum;
    sum = sum * 10 + (number % 10);
    return find_ans(number = number / 10);
}

bool check_palindrome(int number1, int number2)
{
    if (number1 == number2)
        return true;
    return false;
}

int main()
{
    int number = 156489;
    // cout << find_ans(number);
    int number2 = find_ans(number);
    cout << check_palindrome(number, number2);
    return 0;
}