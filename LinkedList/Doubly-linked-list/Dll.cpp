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

Node *ConverLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *new_node = new Node(arr[i]);
        new_node->prev = mover;
        mover->next = new_node;
        mover = new_node;
    }
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

Node *deleteFirst(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }
    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    Node *prev = tail->prev;
    prev->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

Node *removeKthElement(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    int count = 0;
    Node *kthNode = head;
    while (kthNode != nullptr)
    {
        count += 1;
        if (count == k)
            break;
        kthNode = kthNode->next;
    }

    Node *prev = kthNode->prev;
    Node *front = kthNode->next;
    if (prev == nullptr && front == nullptr)
    {
        return nullptr;
    }
    if (prev == nullptr)
    {
        return deleteFirst(head);
    }
    if (front == nullptr)
    {
        return deleteTail(head);
    }
    prev->next = front;
    front->prev = prev;
    kthNode->next = nullptr;
    kthNode->prev = nullptr;
    delete kthNode;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = ConverLL(arr);
    Traverse(head);
    head = removeKthElement(head, 4);
    Traverse(head);
    return 0;
}