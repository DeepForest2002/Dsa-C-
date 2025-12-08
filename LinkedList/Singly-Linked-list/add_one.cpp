#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *convertLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *new_node = new Node(arr[i]);
        mover->next = new_node;
        mover = new_node;
    }
    return head;
}

void traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int convertVal(Node *head)
{
    int val = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        val = val * 10 + temp->data;
        temp = temp->next;
    }
    return val + 1;
}

Node *toLinkedList(int val)
{
    Node *dummy = new Node(-1);
    Node *mover = dummy;
    while (val)
    {
        Node *new_node = new Node(val % 10);
        mover->next = new_node;
        mover = new_node;
        val = val / 10;
    }
    return dummy->next;
}

Node *reverse(Node *head)
{
    Node *temp = head;
    Node *front = nullptr;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main()
{
    vector<int> arr = {9};
    Node *head = convertLL(arr);
    traverse(head);
    int val = convertVal(head);
    cout << val << endl;
    head = toLinkedList(val);
    traverse(head);
    head = reverse(head);
    traverse(head);
    return 0;
}