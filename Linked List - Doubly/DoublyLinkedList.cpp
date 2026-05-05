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

    if(head != NULL)
    {
        head->prev = tmp;
    }
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
    else
    {
        Node* cur = head;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        tmp->prev = cur;
    }
}

void deleteNode(int v)
{
    if(head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    else if(head->data == v)
    {
        Node* tmp = head;
        head = head->next;
        if(head != NULL)
        {
            head->prev = NULL;
        }
        delete tmp;
        cout << v << " deleted successfully." << endl;
        return;
    }
    else
    {
        Node* cur = head->next;
        while(cur != NULL && cur->data != v)
        {
            cur = cur->next;
        }
        if(cur == NULL)
        {
            cout << v << " not found." << endl;
            return;
        }

        Node* prev = cur->prev;
        prev->next = cur->next;
        if(prev->next != NULL)
        {
            prev->next->prev = prev;
        }
        delete cur;
        cout << v << " deleted successfully." << endl;
        return;
    }
}

bool search(int v)
{
    Node* cur = head;
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            cout << v << " found successfully." << endl;
            return true;
        }
        cur = cur->next;
    }
    cout << v << " not found." << endl;
    return false;
}

void sort()
{
    for(Node* i = head; i != NULL; i = i->next)
    {
        for(Node* j = i->next; j != NULL; j = j->next)
        {
            if(j->data < i->data)
            {
                int tmp = i->data;
                i->data = j->data;
                j->data = tmp;
            }
        }
    }
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
    search(32);
    search(0);

    sort();
    display();
}
