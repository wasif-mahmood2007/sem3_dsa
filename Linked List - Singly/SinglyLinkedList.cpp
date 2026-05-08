#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* list = NULL;

//Insert at Beginning
void insertAtBeginning(int v)
{
    Node* tmp = new Node{v, list};
    list = tmp;
}

//Insert at End
void insertAtEnd(int v)
{
    Node* tmp = new Node{v, NULL};

    if(list == NULL)
    {
        list = tmp;
        return;
    }

    Node* cur = list;
    while(cur->next != NULL) cur = cur->next;
    cur->next = tmp;
}

//Delete Node
void deleteNode(int v)
{
    if(list == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }
    if(list->data == v)
    {
        Node* tmp = list;
        list = list->next;
        delete tmp;
        cout << v << " Deleted.\n";
        return;
    }

    Node* prev = list;
    Node* cur = list->next;
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            prev->next = cur->next;
            delete cur;
            cout << v << " Deleted.\n";
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    cout << "Can't find " << v << ".\n";
}

//Search Node
bool search(int v)
{
    if(list == NULL)
    {
        cout << "List is Empty.\n";
        return false;
    }

    Node* cur = list;
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            cout << v << " found.\n";
            return true;
        }
        cur = cur->next;
    }
    cout << "Can't find " << v << ".\n";
    return false;
}

//Sort List
void sort()
{
    if(list == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    for(Node* i = list; i != NULL; i = i->next)
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

//Display List
void display()
{
    if(list == NULL)
    {
        cout << "List is Empty.\n";
        return;
    }

    Node* cur = list;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

//Display Forward using recursion
void displayForward(Node* cur)
{
    if(cur == NULL) return;
    cout << cur->data << " ";
    displayForward(cur->next);
}

//Display Backward using recursion
void displayBackward(Node* cur)
{
    if(cur == NULL) return;
    displayBackward(cur->next);
    cout << cur->data << " ";
}

int main()
{
    //LinkList test
    insertAtBeginning(12);
    insertAtEnd(25);
    insertAtBeginning(72);
    insertAtEnd(57);
    insertAtBeginning(2);
    display();
    cout << endl;

    //Search test
    search(2);
    search(35);
    cout << endl;

    //Sort test
    sort();
    cout << "Sorted list: ";
    display();
    cout << endl;

    //Delete test
    deleteNode(10);
    display();
    deleteNode(2);
    deleteNode(57);
    display();
    cout << endl;

    //Using recursion to display the list in both forward and backward order
    displayForward(list);
    cout << endl;
    displayBackward(list);
    cout << endl;

    return 0;
}
