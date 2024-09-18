#include <iostream>
#include <cmath>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const int Maximum_Number = 200000;

class Priority_Queue
{
    private:
    int lower[Maximum_Number];
    int upper[Maximum_Number];
    int lowersize;
    int uppersize;

    void maxHeapifyDown(int i)
    {
        int largest = i;
        int leftchild = 2 * i + 1;
        int rightchild = 2 * i + 2;
    
        if (leftchild < lowersize && lower[leftchild] > lower[i])
        {
            largest = leftchild;
        }
        if (rightchild < lowersize && lower[rightchild] > lower[largest])
        {
            largest = rightchild;
        }

        if(largest != i)
        {
            swap(lower[i],lower[largest]);
            maxHeapifyDown(largest);    
        }
    }

    void minHeapifyDown(int i)
    {
        int smallest = i;
        int leftchild = 2*i + 1;
        int rightchild = 2*i + 2;

        if(leftchild < uppersize && upper[leftchild] < upper[i])
        {
            smallest = leftchild;
        }
        if(rightchild < uppersize && upper[rightchild] < upper[smallest])
        {
            smallest = rightchild;
        }

        if(smallest != i)
        {
            swap(upper[i],upper[smallest]);
            minHeapifyDown(smallest);
        }
    }

    void maxHeapifyUp(int i)
    {
        while(i > 0 && lower[(i-1)/2] < lower[i])
        {

            swap(lower[i],lower[((i-1)/2)]);
            i = (i-1)/2;
        }
    }

    void minHeapifyUp(int i)
    {
        while(i > 0 && lower[(i-1)/2] > upper[i])
        {
            swap(upper[i],upper[((i-1)/2)]);
            i = (i-1)/2;
        }
    }


    public:
    Priority_Queue()
    {
        lowersize = 0;
        uppersize = 0;
    }

    bool empty()
    {
        if(lowersize == 0 && uppersize == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int sale)
    {
        if(lowersize == 0 || sale <= lower[0])
        {
            lower[lowersize++] = sale;
            maxHeapifyUp(lowersize - 1);
        }
        else
        {
            upper[uppersize++] = sale;
            minHeapifyUp(uppersize - 1);
        }

//Balancing the heaps
        if (lowersize > uppersize + 1) 
        {
            uppersize++;
            upper[uppersize] = lower[0];
            swap(lower[0],lower[--lowersize]);
            maxHeapifyDown(0);
            minHeapifyUp(uppersize - 1);
        }
        else if (uppersize > lowersize)
        {
            lowersize++;
            lower[lowersize] = upper[0];
            swap(upper[0],upper[--uppersize]);
            minHeapifyDown(0);
            maxHeapifyUp(lowersize - 1);
        }
    }

    void pop() {
        if (lowersize > uppersize) 
        {
            swap(lower[0], lower[--lowersize]);
            maxHeapifyDown(0);
        } 
        else if (uppersize > 0) 
        {
            swap(upper[0], upper[--uppersize]);
            minHeapifyDown(0);
        }
    }

    void remove(int sale)
    {
        bool removed = false;

        for(int i=0;i<lowersize;i++)
        {
            if(lower[i] == sale)
            {
                swap(lower[i], lower[--lowersize]);
                maxHeapifyDown(i);
                removed = true;
                break;
            }
        }

        if(!removed)
        {
            for(int i=0;i<uppersize;i++)
            {
                if(upper[i] == sale)
                {
                    swap(upper[i],upper[--uppersize]);
                    minHeapifyDown(i);
                    break;
                }
            }
        }
    
        if(lowersize > uppersize + 1) 
        {
            upper[uppersize++] = lower[0]; 
            swap(lower[0], lower[--lowersize]); 
            maxHeapifyDown(0);
            minHeapifyUp(uppersize - 1); 
        } 
        else if (uppersize > lowersize) 
        {
            lower[lowersize++] = upper[0];
            swap(upper[0], upper[--uppersize]); 
            minHeapifyDown(0);
            maxHeapifyUp(lowersize - 1); 
        }
    }




    float getMedian() {
        if (lowersize > uppersize) 
        {
            return lower[0]; 
        } 
        else 
        {
            return (lower[0] + upper[0]) / 2.0; 
        }
    }
};

int main() {
    int n, d;
    int freemaggidays = 0; 

    cin >> n >> d;

    int sales[Maximum_Number]; 

    for (int i = 0; i < n; ++i) 
    {
        cin >> sales[i];
    }

    Priority_Queue Priority_Queue;

    for (int i = 0; i < d; ++i) 
    {
        Priority_Queue.push(sales[i]);
    }

    
    for (int i = d; i < n; ++i) {
        // Median of the last 'd' days
        float median = Priority_Queue.getMedian();

       
        if (sales[i] >= (median + sales[0])) 
        {
            freemaggidays++;
        }

        // Update the priority queue remove the sale from 'i - d' days ago and insert today's sale
        Priority_Queue.remove(sales[i - d]);
        Priority_Queue.push(sales[i]);
    }

    cout << freemaggidays << endl;

    return 0;
}