#include <iostream>
using namespace std;
int main()
{
    /*
    Operators in c++

    Arithematic Operators= +, -, *, %, /
    Relational Operators / Comparision Operators (Compare two or more values)
    - >,<, >=,<=,==,!=

    Logical Operators = and (&&), or(||), not(!)
    What does not do ?? -- If some value is true it converts it into false
    and if some value is false it converts it into true

    Assignment Operator = Assinging a value to a variable

    Increment and Decrement Operator
    ++ = Increases value by 1
    -- = Decreases value by 1

    Post Increment/decrement (var++/--)
     and
    Pre increment/decrement (++/-- var)

    Bitwise operator &,|,^,~,<<,>>
    */

    int age = 17;
    bool driving_license = true;

    if (age >= 18 || driving_license == true)
    {
        cout << "You are eligible" << endl;
    }
    else
    {
        cout << "You are not eligible" << endl;
    }

    bool isLoggedin = true;

    // Condition - if logged in then show him/her all the data she has
    if (!isLoggedin)
    {
        cout << "You are not logged in" << endl;
    }
    else
    {
        cout << "This is the home page" << endl;
    }

    int val = 10;
    cout << val++ << endl;

    // Bitwise operations
    int var1 = 5; // 0101
    int var2 = 8; // 1000
    cout << (var1 | var2) << endl;
    cout << "Complement of var1 is " << (~var1) << endl;

    /*
    left Shift (<<) and Right Shift (>>)
    left Shift 5= 0101 = 1010 (double)=10
    right shift =0101 =10 (half)=2
    */
    return 0;
}