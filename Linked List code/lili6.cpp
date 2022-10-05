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

Node *delHead(Node *head) //time complexity is O(1)
{
    if (head == NULL)
    {
        head = NULL;
        return head;
    }
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

Node *delEnd(Node *head) //time complexity is O(1)
{
    if (head == NULL || head->next == NULL) //this is done to avoid segmentation error
    {
        head = NULL;
        return head;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = NULL;
        return head;
    }
}

int main()
{
    Node *head = new Node(10); //this is a better way to makeing a lili
    head->next = new Node(20); //without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlist(head);
    cout << endl;
    head = delHead(head);
    head = delEnd(head);
    head = delEnd(head);
    printlist(head);
    return 0;
}