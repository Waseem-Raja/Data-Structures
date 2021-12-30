#include <iostream>
using namespace std;

class Dequeue
{
    int front;
    int Delfront;
    int rear;
    int Delrear;
    int count;
    int Deque[10];

public:
    Dequeue()
    {
        front = 0;
        rear = 10;
        Delfront = -1;
        Delrear = 9;
        count = -1;
    }
    int InsertAtFront(int element)
    {
        if (!isfull())
        {
            Deque[++front] = element;
            count++;
        }
        else
            cout << "Deque is full can't insert " << endl;
    }
    int DeleteAtFront()
    {
        if (!isempty())
        {
            int element;
            element = Deque[Delfront++];
            count--;
            return (element);
        }
        else
            cout << "Deque is empty so can't delete" << endl;
    }
    int InsertAtRear(int element)
    {
        if (!isfull())
        {
            Deque[--rear] = element;
            count++;
        }
        else
            cout << "Deque is full can't insert " << endl;
    }
    int DeleteAtRear()
    {
        if (!isempty())
        {
            int element;
            element = Deque[Delrear--];
            count--;
            return (element);
        }
        else
            cout << "Deque is empty so can't delete" << endl;
    }
    bool isfull()
    {
        return (count == 9);
    }
    bool isempty()
    {
        return count == -1;
    }
    int Numberofelements()
    {
        return count + 1;
    }
    void display()
    {
        if (!isempty())
        {
            int i;
            if (Delfront = -1)
                i = 0;
            else
                i = Delfront;
            while (i <= Delrear)
            {
                cout << Deque[i] << endl;
                i++;
            }
        }
        else
            cout << "Deque is empty so can't display" << endl;
    }
};

int main()
{
    Dequeue list;
    list.InsertAtFront(9);
    list.InsertAtFront(9);
    list.InsertAtFront(9);
    list.InsertAtFront(9);
    list.InsertAtFront(9);
    list.InsertAtRear(6);
    list.InsertAtRear(6);
    list.InsertAtRear(6);
    list.InsertAtRear(6);
    list.InsertAtRear(6);

    cout << "Number of elements" << list.Numberofelements() << endl;
    list.DeleteAtFront();
     list.DeleteAtRear();
    list.display();
}