#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
};

Node *Convert2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *new_node = new Node(arr[i]);
        mover->next = new_node;
        new_node->prev = mover;
        mover = new_node;
    }
    return head;
}

Node *InsertFirst(Node *head, int data)
{
    Node *newHead = new Node(data);
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}

Node *InserBeforetLast(Node *head, int data)
{
    if (head->next == nullptr)
    {
        return InsertFirst(head, data);
    }
    Node *new_node = new Node(data);
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->prev;
    new_node->next = tail;
    tail->prev = new_node;
    new_node->prev = prev;
    prev->next = new_node;
    return head;
}

void Traverse(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse_list(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *previous = nullptr;
    Node *current = head;
    while (current != nullptr)
    {
        previous = current->prev;
        current->prev = current->next;
        current->next = previous;
        current = current->prev;
    }
    return previous->prev;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = Convert2LL(arr);
    Traverse(head);
    cout << "After inserting before last" << endl;
    head = InserBeforetLast(head, 7);
    Traverse(head);

    head = reverse_list(head);
    cout << "After reversing Linkedlist" << endl;
    Traverse(head);

    return 0;
}