#include <bits/stdc++.h>
using namespace std;
int size = 5;

void push(int x, vector<int> &arr)
{
    if (arr.size() >= size)
    {
        cout << "Stack is full" << endl;
        return;
    }
    arr.push_back(x);
    cout << x << " element insertion done" << endl;
}

void pop(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        cout << "Stack is already empty" << endl;
        return;
    }
    cout << arr[arr.size() - 1];
    arr.pop_back();
    cout << "Pop out is done" << endl;
}

int main()
{
    vector<int> arr;
    push(5, arr);
    pop(arr);
    return 0;
}