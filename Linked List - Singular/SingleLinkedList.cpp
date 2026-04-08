#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* list = NULL;

void insert(int value){
    Node* tmp = new Node;
    
    tmp->data=value;
    tmp->next=NULL;
    
    if(list == NULL)
    {
        list=tmp;
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

bool search(int value){
    Node* cur = list;
    while(cur != NULL)
    {
        if(value == cur->data)
        {
            return true;
        }
        cur = cur->next;
    }
    
    return false;
}

void deleteNode(int value){
    if(list == NULL) //if list is empty
    {
        return;
    }
    else if(list->data == value) //if required value is in first node
    {
        Node* cur = list;
        list = list->next;
        delete cur;
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

void print(){
    Node* cur = list;
    while(cur != NULL)
    {
        cout << cur->data  << "\n";
        cur = cur->next;
    }
}

int main() {
    //LinkList test
    insert(12);
    insert(25);
    insert(72);
    insert(57);
    insert(2);
    print();
    //Search test
    if(search(2)){
        cout << "Found.\n";
    }
    else
    {
        cout << "Doesn't Exist.\n";
    }
    //Delete test
    deleteNode(10);
    print();
    deleteNode(12);
    deleteNode(57);
    print();

    return 0;
}