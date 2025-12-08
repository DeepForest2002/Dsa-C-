#include <iostream>
using namespace std;

void print_pattern1(int row, int col)
{
    for (int i = 1; i <= row; i++) // row 0<4 1<4 2<4 3<4 4<4
    {
        for (int j = 1; j <= col; j++) // col 0<4 1<4 2<4 3<4 4<4
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void patter2(int row)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void patter3(int row)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        // inner for loop for col
        for (int j = col; j >= i; j--)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void pattern5(int row, int col)
{
    for (int i = 1; i <= row; i++)
    {
        // inner for loop for col
        int count = 0;
        for (int j = col; j >= i; j--)
        {
            cout << ++count << " ";
        }
        cout << endl;
    }
}

int main()
{

    // print_pattern1(4, 4);
    // patter2(4);
    // patter3(5);

    pattern5(5, 5);
    return 0;
}