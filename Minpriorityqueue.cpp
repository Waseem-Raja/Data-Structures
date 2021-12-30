//MINIMUM PRIORITY QUEUE
#include <iostream>
using namespace std;

class Minpriorityqueue
{
    int *arr;
    int size;

public:
    Minpriorityqueue()
    {
        this->size = -1;
        arr = new int[10];
    }
    int parent(int i)
    {

        return (i -1) / 2;
    }
    void decreasekey(int i, int key)
    {
        arr[i] = key;
        while (i > 0 && arr[parent(i)] > arr[i])
        {

            int a = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = a;
            i = parent(i);
        }
    }

    void insert(int key)
    {
        this->size = this->size + 1;
        arr[this->size] = key;
        decreasekey(this->size, key);
    }
    int getMin()
    {

        return arr[0];
    }
    void minheapify(int arr[], int i, int size)
    {
        int t = 0;
        int minimumm = 0;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if ((arr[left] > arr[i]) && (left < size))
            minimumm = i;
        else
        {
            if (left < size)
            {
                minimumm = left;
                t = 1;
            }
        }
        if (arr[right] < arr[minimumm] && right < size)
        {
            minimumm = right;
            t = 2;
        }
        else if (t == 0)
        {
            minimumm = i;
        }
        if (minimumm != i)
        {
            int m = arr[i];
            arr[i] = arr[minimumm];
            if (t == 1)
            {
                arr[left] = m;
            }
            else if (t == 2)
                arr[right] = m;

            minheapify(arr, minimumm, size);
        }
    }
    int extract()
    {

        int min = arr[0];
        arr[0] = arr[this->size - 1];
        this->size = this->size - 1;
        minheapify(arr, 0, this->size);
        return min;
    }

    void display()
    {

        for (int i = 0; i < this->size; i++)
            cout << arr[i] << " ";
    }
};
int main()
{
    Minpriorityqueue m;
    m.insert(45);
    m.insert(20);
    m.insert(14);
    m.insert(12);
    m.insert(31);
    m.insert(7);
    m.insert(11);
    m.insert(13);
    m.insert(7);
    // cout<<m.getMin();
    cout << m.extract();
    cout << endl;
    // m.display();
    m.decreasekey(3,1);
     cout<<m.getMin()<<endl;

    m.display();
}
