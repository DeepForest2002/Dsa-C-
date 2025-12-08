#include <iostream>
using namespace std;

int find_ans(int sum, int number)
{
    if (number == 0)
        return sum;
    sum += number % 10;
    return find_ans(sum, number / 10);
}

int find_ans2(int number)
{
    if (number == 0)
        return number;
    return number % 10 + find_ans2(number / 10);
}

int main()
{
    int number;
    cout << "enter the number" << endl;
    cin >> number;
    int ans = find_ans2(number);
    cout << ans;
    return 0;
}