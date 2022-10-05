#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) //this is used to print all the elem in a lili
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
}

Node *insertBegin(Node *head, int x) //this insets the nodes at the beinging of the lili its time complexity is O(1)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

Node *insertEnd(Node *head, int x) //time complexity is O(n)as u have to traverse though all elem before adding the element.
{
    Node *temp = new Node(x);
    if (head == NULL) //null case is very imp otherwise it will give segmentaiton error.
    {
        return temp;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int main()
{
    Node *head = NULL;
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    head = insertEnd(head, 40);
    printlist(head);
    return 0;
}