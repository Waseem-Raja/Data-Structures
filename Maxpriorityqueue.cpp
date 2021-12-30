//MAXIMUM PRIORITY QUEUE
#include <iostream>
using namespace std;

class Maxpriorityqueue
{
    int *arr;
    int size;

public:
    Maxpriorityqueue()
    {
        this->size = -1;
        arr = new int[10];
    }
    int parent(int i)
    {

        return (i - 1) / 2;
    }
    void increasekey(int i,int key)
    {
        arr[i]=key;
        while (i > 0 && arr[parent(i)] < arr[i])
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
        increasekey(this->size, key);
    }
    int getMax()
    {

        return arr[0];
    }
    void maxheapify(int arr[], int i, int size)
    {
        int t = 0;
        int largest = 0;
        int left = 2 * i + 1;  //  calculating left index
        int right = 2 * i + 2; //right index
        if ((arr[left] < arr[i]) && (left < size))
            largest = i;
        else
        {
            if (left < size) //incase left index is not present in array
            {
                largest = left;
                t = 1; //this indicates that largest value was of left index so i have to change arr[i] with left index
            }
        }
        if (arr[right] > arr[largest] && right < size)
        {
            largest = right;
            t = 2; //this indicates that largest value was of right index so i have to change arr[i] with right index
        }
        else if (t == 0) //incase if index is out of bounds i.e not present in the array then largest value will be arr[i] itself
        {
            largest = i;
        }
        if (largest != i)
        {
            int m = arr[i];
            arr[i] = arr[largest]; //exchanging  largest value with arr[i]
            if (t == 1)
            {
                arr[left] = m;
            }
            else if (t == 2)
                arr[right] = m;

            maxheapify(arr, largest, size);
        }
    }
    int extract()
    {

        int max = arr[0];
        arr[0] = arr[this->size - 1];
        this->size = this->size - 1;
        maxheapify(arr, 0, this->size);
        return max;
    }

    void display()
    {

        for (int i = 0; i < this->size; i++)
            cout << arr[i] << " ";
    }
};
int main()
{
    Maxpriorityqueue m;
    m.insert(45);
    m.insert(20);
    m.insert(14);
    m.insert(12);
    m.insert(31);
    m.insert(7);
    m.insert(11);
    m.insert(13);
    m.insert(7);
    // cout<<m.getMax();
    // cout << m.extract();
    cout<<endl;
    // m.display();
    // m.increasekey(1,50);
    m.display();
}


