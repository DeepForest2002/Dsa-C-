#include <iostream>
using namespace std;

void print_pattern(int row, int col)
{
    if (row == 0)
        return;
    for (int i = 0; i < col; i++)
    {
        cout << "*" << " ";
    }
    cout << endl;
    print_pattern(row -= 1, col -= 1);
}

int main()
{
    int row = 4;
    int col = 4;
    print_pattern(row, col);
    return 0;
}