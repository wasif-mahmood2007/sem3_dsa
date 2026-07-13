#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int v)
{
    Node* tmp = new Node{v, NULL, head};

    if(head != NULL) head->prev = tmp;
    head = tmp;
}

void insertAtEnd(int v)
{
    Node* tmp = new Node{v, NULL, NULL};

    if(head == NULL)
    {
        head = tmp;
        return;
    }
    
    Node* cur = head;
    while(cur->next != NULL) cur = cur->next;
    tmp->prev = cur;
    cur->next = tmp;
}

void deleteNode(int v)
{
    if(head == NULL) return;
    if(head->data == v)
    {
        Node* tmp = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
        delete tmp;
        return;
    }

    Node* cur = head->next;
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            Node* prev = cur->prev;
            prev->next = cur->next;
            if(prev->next != NULL) prev->next->prev = prev;
            delete cur;
            return;
        }
        cur = cur->next;
    }
}

bool search(int v)
{
    Node* cur = head;
    while(cur != NULL)
    {
        if(cur->data == v) return true;
        cur = cur->next;
    }
    return false;
}

void sort()
{
    if(head == NULL) return;

    for(Node* i = head; i != NULL; i = i->next)
    {
        for(Node* j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
}

void reverse()
{
    if(head == NULL) return;

    Node* cur = head;
    Node* tmp = NULL;

    while(cur != NULL)
    {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;

        cur = cur->prev;
    }

    if(tmp != NULL) head = tmp->prev;
}

void display()
{
    Node* cur = head;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void displayForward(Node* cur)
{
    if(cur == NULL) return;
    cout << cur->data << " ";
    displayForward(cur->next);
}

void displayBackward(Node* cur)
{
    if(cur == NULL) return;
    displayBackward(cur->next);
    cout << cur->data << " ";
}

int main()
{  
    insertAtBeginning(47);
    insertAtBeginning(6);
    insertAtBeginning(1);
    insertAtEnd(19);
    insertAtEnd(55);
    insertAtEnd(32);
    display();

    deleteNode(6);
    deleteNode(8);
    display();
    cout << search(32) << endl;
    cout << search(0) << endl;

    sort();
    display();
}
