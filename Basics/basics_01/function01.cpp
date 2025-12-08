
#include <iostream>
using namespace std;
/*
syntax- function_type function_name (parameters){
code
}*/
void function_name()
{
    cout << "Hello World" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    cout << "Sayan Pramanik" << endl;
    // return 0;
}

// lets create a function that returns something
int func1()
{
    return 12;
}

float func2()
{
    return 12.4;
}

int sum(int a, int b)
{
    return (a + b);
}

int function_find_element(int arr2[], int size)
{
}

int main()
{
    // void function -does not  returns anything
    // function_name();
    int var1 = func1();
    int var2 = func2();

    int sum1 = sum(12, 14);
    cout << sum1 << endl;

    // How to pass an array in function arr-10(int+) pointer-4 bytes
    int arr2[] = {14, 15, 18, 20, 12, 11, 30, 25, 20, 26};
    return 0;
}