#include <iostream>
using namespace std;

const int MAX = 100;
int heap[MAX];
int heapSize = 0;

void upheapify(int heap[], int ind)
{
    if(ind == 0) return;

    int parent = (ind - 1) / 2;
    if(heap[parent] < heap[ind])
    {
        swap(heap[parent], heap[ind]);
        upheapify(heap, parent);
    }
}

void insert(int v)
{
    if(heapSize == MAX) return;

    heap[heapSize] = v;
    upheapify(heap, heapSize);
    heapSize++;
}

void downheapify(int heap[], int ind, int heapSize)
{
    int left = ind * 2 + 1;
    int right = ind * 2 + 2;
    if(left >= heapSize) return;

    int largest = ind;
    if(left < heapSize && heap[left] > heap[largest]) largest = left;
    if(right < heapSize && heap[right] > heap[largest]) largest = right;

    if(largest != ind)
    {
        swap(heap[ind], heap[largest]);
        downheapify(heap, largest, heapSize);
    }
}

void deleteRoot()
{
    if(heapSize == 0) return;

    heapSize--;
    swap(heap[0], heap[heapSize]);
    downheapify(heap, 0, heapSize);
}

bool search(int v)
{
    for(int i = 0; i < heapSize; i++)
    {
        if(heap[i] == v) return true;
    }
    return false;
}

void heapSort()
{
    int tmp[MAX];
    int tmpSize = heapSize;
    for(int i = 0; i < heapSize; i++) tmp[i] = heap[i];

    for(int i = tmpSize - 1; i > 0; i--)
    {
        swap(tmp[0], tmp[i]);
        downheapify(tmp, 0, i);
    }

    cout << "Sorted:";
    for(int i = 0; i < tmpSize; i++) cout << " " << tmp[i];
    cout << endl;
}

void display()
{
    if(heapSize == 0) return;

    for(int i = 0; i < heapSize; i++) cout << heap[i] << " ";
    cout << endl;
}

void displayLevels()
{
    if(heapSize == 0) return;

    int levelNodes = 1;
    int count = 0;

    for(int i = 0; i < heapSize; i++)
    {
        cout << heap[i] << " ";
        
        count++;
        if(count == levelNodes)
        {
            cout << endl;
            levelNodes *= 2;
            count = 0;
        }
    }
    if(count != 0) cout << endl;
}

int main()
{
    insert(40);
    insert(20);
    insert(30);
    insert(10);
    insert(50);
    insert(75);

    displayLevels();

    deleteRoot();
    display();

    cout << search(30) << endl;
    cout << search(40) << endl;

    heapSort();
}
