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

void printlist(Node *head) // this is used to print all the elem in a lili
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << (curr->data) << " ";
        curr = curr->next;
    }
};

int main()
{
    Node *head = new Node(10); // this is a better way to makeing a lili
    head->next = new Node(20); // without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlist(head);
}