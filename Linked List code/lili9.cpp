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

void printMiddle(Node *head) //this is ineffiecient sol
{
    if (head == NULL)
    {
        return;
    }
    int ctr = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        ctr++;
        curr = curr->next;
    }
    curr = head;
    for (int i = 0; i < (ctr / 2); i++)
    {
        curr = curr->next;
    }
    cout << curr->data << endl;
}

void priMidEff(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << (slow->data) << endl;
}

int main()
{
    // Node *head = NULL;
    Node *head = new Node(10); //this is a better way to makeing a lili
    head->next = new Node(20); //without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    priMidEff(head);
    printlist(head);
}