#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int heapSize = 0;

void upHeapify(int arr[], int ind)
{
    if(ind == 0) return;

    int parent = (ind - 1) / 2;
    if(arr[parent] < arr[ind])
    {
        swap(arr[parent], arr[ind]);
        upHeapify(arr, parent);
    }
}

void downHeapify(int arr[], int ind, int size)
{
    int left = ind * 2 + 1;
    int right = ind * 2 + 2;

    if(left >= size) return;

    int largest = ind;
    if(left < size && arr[left] > arr[largest]) largest = left;
    if(right < size && arr[right] > arr[largest]) largest = right;

    if(largest != ind)
    {
        swap(arr[ind], arr[largest]);
        downHeapify(arr, largest, size);
    }
}

void insert(int v)
{
    if(heapSize == MAX)
    {
        cout << "Heap's full.\n";
        return;
    }

    arr[heapSize] = v;
    upHeapify(arr, heapSize);
    heapSize++;
}

void deleteRoot()
{
    if(heapSize == 0)
    {
        cout << "Heap's empty.\n";
        return;
    }

    swap(arr[0], arr[heapSize - 1]);
    heapSize--;
    downHeapify(arr, 0, heapSize);
}

bool search(int v)
{
    if(heapSize == 0)
    {
        cout << "Heap's empty.\n";
        return false;
    }

    for(int i = 0; i < heapSize; i++)
    {
        if(arr[i] == v)
        {
            cout << v << " found.\n";
            return true;
        }
    }
    cout << v << " not found.\n";
    return false;
}

void heapSort()
{
    //copy original array
    int tmp[MAX];
    int tmpSize = heapSize;
    for(int i = 0; i < heapSize; i++) tmp[i] = arr[i];

    for(int i = tmpSize - 1; i > 0; i--)
    {
        swap(tmp[0], tmp[i]);
        downHeapify(tmp, 0, i);
    }

    cout << "Sorted:";
    for(int i = 0; i < tmpSize; i++)
    {
        cout << " " << tmp[i];
    }
    cout << endl;
}

void display()
{
    if(heapSize == 0)
    {
        cout << "Heap's empty.\n";
        return;
    }

    for(int i = 0; i < heapSize; i++) cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    insert(40);
    insert(20);
    insert(30);
    insert(10);
    insert(50);

    display();

    deleteRoot();
    display();

    search(30);
    search(99);

    heapSort();

    display();
}