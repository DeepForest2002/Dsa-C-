#include <iostream>
using namespace std;
int main()
{
    /*
    Loops - for, while, do-while

    while - Entry control loop
    do-while - exit control loop

    syntax

    for(initialization,condition,increment)

    for(int i=0;i<=10;i++){
        cout<<i<<endl;
    }
    */

    int i = 0;
    while (i < 10)
    {
        // cout << i << endl;
        // i++;
        i = i + 1;
    }

    int var = 10; //
    do
    {
        cout << var << endl;
    } while (var < 10);

    return 0;
}