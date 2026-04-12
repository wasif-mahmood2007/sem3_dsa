#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* list = NULL;

void insert(int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;
    
    if(list == NULL)
    {
        list = tmp;
    }
    else
    {
        Node* cur = list;
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void deleteNode(int value)
{
    if(list == NULL) //if list is empty
    {
        cout << "List is Empty\n";
        return;
    }
    else if(list->data == value) //if required value is in first node
    {
        Node* tmp = list;
        list = list->next;
        delete tmp;
        return;
    }
    else //if required value presents further in the list
    {
        Node* cur = list->next;
        Node* prev = list;
        while(cur != NULL)
        {
            if(cur->data == value)
            {
                prev->next = cur->next;
                delete cur;
                return;
            }
            prev = cur;
            cur = cur->next;
        }
    }
}

bool search(int value)
{
    Node* cur = list;
    while(cur != NULL)
    {
        if(cur->data == value)
        {
            return true;
        }
        cur = cur->next;
    }
    
    return false;
}

void sort()
{
    if(list == NULL)
    {
        cout << "List is Empty\n";
        return;
    }

    for(Node* i = list; i->next != NULL; i = i->next)
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
    Node* cur = list;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    //LinkList test
    insert(12);
    insert(25);
    insert(72);
    insert(57);
    insert(2);
    display();
    //Search test
    if(search(2)){
        cout << "Found.\n";
    }
    else
    {
        cout << "Doesn't Exist.\n";
    }
    //Sort test
    sort();
    display();
    //Delete test
    deleteNode(10);
    display();
    deleteNode(2);
    deleteNode(57);
    display();

    return 0;
}