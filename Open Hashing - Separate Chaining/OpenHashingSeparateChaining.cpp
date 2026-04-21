#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

const int hashSize = 10;
Node* HT[hashSize] = {NULL};

void insert(int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;

    int ind = value % hashSize;

    if(HT[ind] == NULL)
    {
        HT[ind] = tmp;
    }
    else
    {
        Node* cur = HT[ind];
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = tmp;
    }
}

void deleteNode(int value)
{
    int ind = value % hashSize;

    if(HT[ind] == NULL)
    {
        cout << value << " not found in the Hashtable." << endl;
        return;
    }
    else if(HT[ind]->data == value)
    {
        Node* tmp = HT[ind];
        HT[ind] = HT[ind]->next;
        delete tmp;
        cout << value << " found and deleted." << endl;
        return;
    }
    else
    {
        Node* cur = HT[ind];
        Node* nxt = HT[ind]->next;

        while(nxt != NULL)
        {
            if(nxt->data == value)
            {
                cur->next = nxt->next;
                delete nxt;
                cout << value << " found and deleted." << endl;
                return;
            }
            cur = cur->next;
            nxt = nxt->next;
        }
        cout << value << " not found." << endl;
        return;
    }
}

bool search(int value)
{
    int ind = value % hashSize;

    if(HT[ind] == NULL)
    {
        cout << value << " not found." << endl;
        return false;
    }

    Node* cur = HT[ind];
    while(cur != NULL)
    {
        if(cur->data == value)
        {
            cout << value << " found." << endl;
            return true;
        }
        cur = cur->next;
    }
    cout << value << " not found in the Hashtable" << endl;
    return false;
}

void display()
{
    for(int i = 0; i < hashSize; i++)
    {
        cout<< i << ":";
        for(Node* cur = HT[i]; cur != NULL; cur = cur->next)
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
    search(84);
    search(54);
    search(3);

    //delete
    deleteNode(74);
    deleteNode(89);
    deleteNode(25);
    deleteNode(76);
    deleteNode(3);
    deleteNode(3);
    display();
    search(3);

    return 0;
}