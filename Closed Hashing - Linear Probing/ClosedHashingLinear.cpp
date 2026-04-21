#include <iostream>
using namespace std;

const int EMPTY = -1;
const int DELETED = -2;
const int hashSize = 10;
int HT[hashSize] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

void insert(int value)
{
    int ind = value % hashSize;
    int start = ind;

    while(HT[ind] != EMPTY && HT[ind] != DELETED)
    {
        ind = (ind + 1) % hashSize;
        if(ind == start)
        {
            cout << "Hashtable is full." << endl;
            return;
        }
    }
    HT[ind] = value;
    cout << value << " inserted at index " << ind << "." << endl;
}

void deleteVal(int value)
{
    int ind = value % hashSize;
    int start = ind;

    while(HT[ind] != EMPTY)
    {
        if(HT[ind] == value)
        {
            HT[ind] = DELETED;
            cout << value << " found and deleted at index " << ind << "." << endl;
            return;
        }

        ind = (ind + 1) % hashSize;
        if(ind == start)
        {
            break;
        }
    }
    cout << value << " not found." << endl;
    return;
}

bool search(int value)
{
    int ind = value % hashSize;
    int start = ind;

    while(HT[ind] != EMPTY)
    {
        if(HT[ind] == value)
        {
            cout << value << " found at index " << ind << "." << endl;
            return true;
        }

        ind = (ind + 1) % hashSize;
        if(ind == start)
        {
            break;
        }
    }
    cout << value << " not found." << endl;
    return false;
}

void display()
{
    for(int i = 0; i < hashSize; i++)
    {
        cout << i << ": " << HT[i] << endl;
    }
}

int main()
{
    //insert
    insert(10);
    insert(20);
    insert(30);
    insert(55);
    insert(2);
    insert(66);
    insert(84);
    insert(99);
    display();

    //search
    search(12);
    search(30);

    //delete
    deleteVal(98);
    deleteVal(99);
    deleteVal(55);
    display();

    deleteVal(10);
    search(30);

    return 0;
}