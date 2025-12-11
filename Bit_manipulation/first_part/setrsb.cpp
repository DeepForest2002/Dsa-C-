#include <iostream>
using namespace std;
int setRsb(int number)
{
    return (number | (number + 1));
}
int main()
{
    int number = 49971;
    cout << setRsb(number);
    return 0;
}