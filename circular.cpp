//Array Representation of Circular Queue
#include <iostream>
using namespace std;
#define size 10
class CircularQueue
{
    int front, rear, newinsert, count, indicate;
    int queue[size];

public:
    CircularQueue()
    {
        front = 0; // firstly front will point to the first index
        rear = -1; // rear to none
        newinsert = -1;
        count = -1;
        indicate = -1;
    }
    int enqueue(int element) // inserting an element
    {
        if (!isfull()) //check for full if full then can't insert
        {
            queue[++rear] = element;        // first incrementing the rear and inserting the element from index 0
            count++;                                  // counting the number of elements inserted in the Queue
            if (rear == size-1)                    // if Queue is full and there is still space left in Queue then we can point rear to the first location and
            {                                              //starting insert elements from ist index to the  number elemnts popped from the queue
                rear = -1;                             // initializing rear to the -1 as it was before
                indicate = rear;                    // this will indicate elemnts are inserted upto end of the Queue
            }
            if (front > 0 && indicate == -1) //if elements are popped and inerting elemnts are done upto the end of the Queue
            {
                if (rear > -1)                           // if new elemnts are inserted in the Queue
                    newinsert = rear;               // newinsert will indicate that new elemnts are inserted at how many are they
            }
        }
        else
            cout << "Queue is full so can't insert" << endl;
    }
    int dequeue()                                         // removing from Queue
    {
        if (!isempty())                                    //check for empty if empty then can't pop
        {
            int element;
            if (front == 10 && newinsert > -1) //this indicates that all elements are popped from Queue upto the end of the Queue
                front = 0;                                    //now if there are new elements to popped then front should start from index 0

            element = queue[front++];             //removing element
            count--;                                           // decrementing the count
            return element;
        }
        else
            cout << "queue is empty can't pop" << endl;
    }
    bool isempty()
    {
        return count == -1;                                 // if count is -1 then no elements were inserted in the Queue
    }

    bool isfull()
    {
        return (count == (size-1));                      //  if count is equal to the size of Queue then Queue is full
    }
    int numberofelements()
    {
        return count + 1;                                     //as i am starting count from 0 so returing count plus one
    }
    void display()
    {
        if (!isempty())
        {
            cout << "Elements in Queue :" << endl;
            if (front == 0)                                 //this is if no elements were removed from Queue and no new inserted elements
            {
                int i = front;
                while (i < numberofelements()) //from front to the number of elemts in the Queue
                {
                    cout << queue[i] << endl;
                    i++;
                }
            }
            else if (front > 0 && newinsert < 0) //this if some elements were removed and no new inserted elements
            {
                int i = front;
                int j = 0;
                while (j < numberofelements()) //from front to the number of elemnts remaining in the Queue
                {
                    cout << queue[i] << endl;
                    i++;
                    j++;
                }
            }
            else
            {
                if (front > 0 && newinsert > -1) // if elements were removed as well as new elements were inserted in the Queue
                {
                    int i = front;
                    while (i <= (size-1)) // for previously inserted elements
                    {
                        cout << queue[i] << endl;
                        i++;
                    }
                    int k = 0;
                    while (k <= rear) // for newlyinserted elements
                    {
                        cout << queue[k] << endl;
                        k++;
                    }
                }
            }
        }
        else
            cout << "Queue is empty so can't display" << endl;
    }
};
int main()
{
    CircularQueue obj;
    obj.enqueue(2);
    obj.enqueue(7);
    obj.enqueue(6);
    obj.enqueue(2);
    obj.enqueue(5);
    obj.enqueue(2);
    obj.enqueue(9);
    obj.enqueue(5);
    obj.enqueue(2);
    obj.enqueue(9);
    cout << "Number of  Elements in Queue:" << obj.numberofelements() << endl; // this should be 10
    obj.display();
    //obj.enqueue(5);

    obj.dequeue(); // removing elemnets from Queue
    obj.dequeue();
    obj.dequeue();
    cout << "Number of  Elements in Queue:" << obj.numberofelements() << endl; // this should be 7
    obj.display();
    obj.enqueue(5); // inserted at first location
    obj.enqueue(5);
    obj.enqueue(5);
    cout << "Number of  Elements in Queue:" << obj.numberofelements() << endl; // this should be 10
    obj.display();
    obj.dequeue(); //dequeue all elements in Queue
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();
    cout << "Number of  Elements in Queue:" << obj.numberofelements() << endl; // this should be 0
    obj.display();                                                             // can't display
    obj.dequeue();                                                             // can't pop
}
