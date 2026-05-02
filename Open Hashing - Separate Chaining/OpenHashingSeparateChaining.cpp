#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

const int hashSize = 10;
Node* ht[hashSize] = {NULL};

void insert(int v)
{
    int ind = v % hashSize;
    Node* tmp = new Node{v, NULL};

    if(ht[ind] == NULL)
    {
        ht[ind] = tmp;
        return;
    }
    
    Node* cur = ht[ind];
    while(cur->next != NULL) cur = cur->next;
    cur->next = tmp;
}

void deleteNode(int v)
{
    int ind = v % hashSize;

    if(ht[ind] == NULL)
    {
        cout << v << " not found.\n";
        return;
    }
    if(ht[ind]->data == v)
    {
        Node* tmp = ht[ind];
        ht[ind] = ht[ind]->next;
        delete tmp;

        cout << v << " found and deleted.\n";
        return;
    }

    Node* prev = ht[ind];
    Node* cur = ht[ind]->next;
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            prev->next = cur->next;
            delete cur;

            cout << v << " found and deleted.\n";
            return;
        }
        prev = prev->next;
        cur = cur->next;
    }
    cout << v << " not found.\n";
    return;
}

bool search(int v)
{
    int ind = v % hashSize;

    if(ht[ind] == NULL)
    {
        cout << v << " not found.\n";
        return false;
    }

    Node* cur = ht[ind];
    while(cur != NULL)
    {
        if(cur->data == v)
        {
            cout << v << " found.\n";
            return true;
        }
        cur = cur->next;
    }
    cout << v << " not found.\n";
    return false;
}

void display()
{
    for(int i = 0; i < hashSize; i++)
    {
        cout << i << ":";
        for(Node* cur = ht[i]; cur != NULL; cur = cur->next)
        {
            cout << " " << cur->data;
        }
        cout << endl;
    }
}

int main()
{
    //insert
    insert(10);
    insert(15);
    insert(25);
    insert(45);
    insert(87);
    insert(62);
    insert(54);
    insert(76);
    insert(16);
    insert(3);
    insert(39);
    insert(69);
    insert(52);
    insert(47);
    insert(41);
    insert(74);
    insert(88);
    insert(5);
    display();

    //search
    search(84); //searching not-existant value
    search(54);
    search(3);

    //delete
    deleteNode(74);
    deleteNode(89); //deleting not-existant value
    deleteNode(25);
    deleteNode(76);
    deleteNode(3);
    deleteNode(3); //deleting alreading deleted value
    display();
    search(3); //searching deleted value
}
