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

Node *ConvertLL(vector<int> arr)
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

Node *InsertHead(Node *head, int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    return temp;
}

Node *InsertLast(Node *head, int value)
{
    Node *temp = head;
    Node *new_node = new Node(value);
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    // temp = new_node;
    return head;
}

Node *InsertK(Node *head, int val, int k)
{
    Node *new_node = new Node(val);
    // If the ll is empty
    if (head == nullptr)
        return new_node;
    // if the val of k is 1
    if (k == 1)
        return InsertHead(head, val);
    Node *temp = head;
    Node *prev = nullptr;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        if (count == k)
        {
            new_node->next = temp;
            prev->next = new_node;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void Traverse_list(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = ConvertLL(arr);
    head = InsertK(head, 14, 4);
    Traverse_list(head);
    return 0;
}