#include <iostream>
#include <stdio.h>

using namespace std;

class Priority_Queue
{
private:
    int *heap;
    int capacity;
    int size;
    bool isMinHeap;

public:
    Priority_Queue(int Default_Capacity, bool isMinHeapType) // Constructor
    {
        heap = new int[Default_Capacity];
        capacity = Default_Capacity;
        size = 0;
        isMinHeap = isMinHeapType;
    }

    ~Priority_Queue() // Destructor to free up memory
    {
        delete[] heap;
    }

    int parent(int i) 
    { 
        return (i - 1) / 2; 
    }

    int leftchild(int i) 
    { 
        return (2 * i + 1); 
    }

    int rightchild(int i) 
    { 
        return (2 * i + 2); 
    }

    void heapifyup(int i)
    {
        if (isMinHeap)
        {
            while (i != 0 && heap[parent(i)] > heap[i])
            {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
        else
        {
            while (i != 0 && heap[parent(i)] < heap[i])
            {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }
    }

    void heapifydown(int i) // Heapify down to maintain heap property
    {
        int l = leftchild(i);
        int r = rightchild(i);
        int parent = i;

        if (isMinHeap)
        {
            if (l < size && heap[l] < heap[i]) // MinHeap
            {
                parent = l;
            }
            if (r < size && heap[r] < heap[parent])
            {
                parent = r;
            }
        }
        else
        {
            if (l < size && heap[l] > heap[i]) // MaxHeap
            {
                parent = l;
            }
            if (r < size && heap[r] > heap[parent])
            {
                parent = r;
            }
        }

        if (parent != i)
        {
            swap(heap[i], heap[parent]);
            heapifydown(parent);
        }
    }

    void resizeHeap()
    {
        int *newheap = new int[capacity * 2]; // New array with double capacity
        for (int i = 0; i < size; i++)
        {
            newheap[i] = heap[i];
        }
        delete[] heap;
        heap = newheap;
        capacity = capacity * 2;
    }

    void push(int value)
    {
        if (size == capacity)
        {
            resizeHeap();
        }

        heap[size] = value;
        size++;
        heapifyup(size - 1);
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        heap[0] = heap[size - 1];
        size--;
        heapifydown(0);
    }

    int top()
    {
        if (size == 0)
        {
            cout << "Priority Queue is empty" << endl;
            return -1;
        }
        return heap[0];
    }

    bool empty() { return size == 0; }

    int getSize() { return size; }
};

int main()
{
    string choice;
    bool isMinHeap;
    cout << "Enter 'min' for Min-Heap or 'max' for Max-Heap: ";
    cin >> choice;

    if (choice == "min")
    {
        isMinHeap = true;
    }
    else
    {
        isMinHeap = false;
    }

    Priority_Queue Priority_Queue(10, isMinHeap); // Create the priority queue with initial capacity 10

    int n;
    cout << "Enter the number of elements to insert: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        Priority_Queue.push(value);
    }

    cout << endl;

    while (true)
    {
        int option;
        cout << "\n 1. Get Top \n 2. Remove Top \n ";
        cin >> option;


         if (option == 1)
        {
            cout << "Top element: " << Priority_Queue.top() << endl;
        }
        else if (option == 2)
        {
            Priority_Queue.pop();
            cout << "Top element Removed " << endl;
        }

        else
        {
            cout << "Invalid optipn " << endl;
        }
    }

    return 0;
}
