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

void nthEnd(Node *head, int k) //prints the nth element from the end of the linked list.
{
    Node *curr = head;
    int ctr = 1;
    while (curr != NULL)
    {
        ctr++;
        curr = curr->next;
    }
    int len = ctr;

    curr = head;
    if (k > len)
    {
        return;
    }
    int i = len - k - 1;
    while (i--)
    {
        curr = curr->next;
    }
    cout << curr->data << endl;
}

void nthEndBETTER(Node *head, int k) //better method to print the nth element from the end.
{
    if (head == NULL)
    {
        return;
    }
    Node *first = head;
    for (int i = 0; i < k; i++)
    {
        if (first == NULL)
        {
            return;
        }
        first = first->next;
    }
    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data << endl;
}

int main()
{
    Node *head = new Node(10); //this is a better way to makeing a lili
    head->next = new Node(20); //without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    nthEndBETTER(head, 3);
    printlist(head);
}