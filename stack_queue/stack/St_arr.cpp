#include <iostream>
#include <limits.h>
using namespace std;

class stack_implement
{
public:
    int top = -1;
    int arr[10];

    void push(int data)
    {
        if (top >= 10)
        {
            cout << "Stack is full";
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    int Top_el()
    {
        if (top == -1)
        {
            return INT_MIN;
        }
        return arr[top];
    }
    void Pop_element()
    {
        if (top != -1)
        {
            top = top - 1;
            return;
        }
        cout << "Stack is empty" << endl;
    }
    int size()
    {
        return top + 1;
    }
};
#include <iostream>
using namespace std;

class Node
{
private:
    Node *top;
    int size;
    Node *next;
    int data;

public:
    Node(int data)
    {
        top = nullptr;
        size = 0;
        next = nullptr;
    }

    void push(int data)
    {
        Node *new_node = new Node(data);
        new_node->next = top;
        top = new_node;
        size++;
    }

    int pop()
    {
        if (size == 0)
        {
            cout << "Stack is empty\n";
            return -1;
        }

        int el = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
        return el;
    }

    int peek()
    {
        if (size == 0)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    Node object;
    object.push(10);

    return 0;
}