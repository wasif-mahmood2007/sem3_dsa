#include <iostream>
using namespace std;

struct Order
{
    int orderID;
    string customer;
    string food;
    Order* next;
};

Order* front = NULL;
Order* rear = NULL;

const int hashSize = 10;
Order* ht[hashSize] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

void hashInsert(Order* tmp)
{
    int start = tmp->orderID % hashSize;

    for(int i = 0; i < hashSize; i++)
    {
        int ind = (start + i) % hashSize;

        if(ht[ind] == NULL)
        {
            ht[ind] = tmp;
            return;
        }
    }
    cout << "Hash Table Full.\n";
}

bool searchOrder(int id)
{
    int start = id % hashSize;

    for(int i = 0; i < hashSize; i++)
    {
        int ind = (start + i) % hashSize;

        if(ht[ind] == NULL) return false;
        if(ht[ind]->orderID == id)
        {
            cout << "Order Found: ";
            cout << "Customer: " << ht[ind]->customer;
            cout << " | Food: " << ht[ind]->food << endl;
            return true;
        }
    }
    cout << "Order not found.\n";
    return false;
}

void hashDelete(int id)
{
    int start = id % hashSize;

    for(int i = 0; i < hashSize; i++)
    {
        int ind = (start + i) % hashSize;

        if(ht[ind] == NULL) return;
        if(ht[ind]->orderID == id)
        {
            ht[ind] = NULL;
            return;
        }
    }
}

void placeOrder(int id, string c, string f)
{
    Order* tmp = new Order{id, c, f, NULL};

    if(front == NULL)
    {
        front = rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }

    hashInsert(tmp);
    cout << "Order #" << id << " placed successfully.\n";
}

void cookNextOrder()
{
    if(front == NULL)
    {
        cout << "Queue Underflow.\n";
        return;
    }

    Order* tmp = front;
    front = front->next;
    if(front == NULL) rear = NULL;
    cout << "Cooking Order #" << tmp->orderID << " for " << tmp->customer << endl;
    hashDelete(tmp->orderID);
    delete tmp;
}

void displayPendingOrders()
{
    if(front == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Pending Orders: \n";
    for(Order* cur = front; cur != NULL; cur = cur->next)
    {
        cout << "OrderID: " << cur->orderID;
        cout << " | Customer: " << cur->customer;
        cout << " | Food: " << cur->food << endl;
    }
    cout << "---------------\n";
}

int main()
{
    placeOrder(101,"Someone","Burger");
    placeOrder(102,"Another one","Pizza");
    placeOrder(103,"Third one","Fries");

    displayPendingOrders();

    searchOrder(102);
    searchOrder(104);

    cookNextOrder();

    displayPendingOrders();
}