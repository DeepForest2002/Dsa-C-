#include <iostream>
using namespace std;
int flip_bit(int n, int i)
{
    // first toogle all the bits of after left shifting 1 by i places and then returns & with n
    return (~(1 << i)) & n;
}

int toogle_bit(int n, int i)
{
    return (1 << i) ^ n;
}

int main()
{
    cout << flip_bit(13, 2) << endl;
    cout << toogle_bit(13, 2);
    return 0;
}