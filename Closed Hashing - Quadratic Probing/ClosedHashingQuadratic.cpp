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
    int quadNum = 1;

    while(HT[ind] != EMPTY && HT[ind] != DELETED)
    {
        ind = (start + quadNum * quadNum) % hashSize;
        quadNum++;

        if(quadNum >= hashSize)
        {
            cout << "Can't insert " << value << ". Hashtable is full." << endl;    
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
    int quadNum = 1;
    
    while(HT[ind] != EMPTY)
    {
        if(HT[ind] == value)
        {
            HT[ind] = DELETED;
            cout << value << " found at index " << ind << " and deleted." << endl;
            return;
        }
        
        ind = (start + quadNum * quadNum) % hashSize;
        quadNum ++;
        
        if(quadNum >= hashSize)
        {
            break;
        }
    }
    
    cout << value << " not found in the Hashtable." << endl;
    return;
}

bool search(int value)
{
    int ind = value % hashSize;
    int start = ind;
    int quadNum = 1;

    while(HT[ind] != EMPTY)
    {
        if(HT[ind] == value)
        {
            cout << value << " found at index " << ind << "." << endl;
            return true;
        }
        
        ind = (start + quadNum * quadNum) % hashSize;
        quadNum ++;
        
        if(quadNum >= hashSize)
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
    insert(64);
    insert(77);
    insert(87);
    insert(56);
    insert(27);
    insert(47);
    display();

    //search
    search(27);
    search(55);

    //delete
    deleteVal(87);
    deleteVal(87);
    display();

    return 0;
}