#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {10, 11, 15, 20, 23};

    // Create an array consisting of float elements and the length of this array will be 5
    //  float arr2[5]={.....}
    /*
    int size = 4 bytes (32 bits)

    Size of array
    */

    int arr2[] = {14, 15, 18, 20, 12, 11, 30, 25};
    // length
    int n = sizeof(arr2) / sizeof(int);

    cout << sizeof(arr2) << endl;
    cout << sizeof(int) << endl;
    cout << "size of this arr2 is " << n << endl;

    /* Traversing an array - print array elements */

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";
    }

    /*
     */
    return 0;
}