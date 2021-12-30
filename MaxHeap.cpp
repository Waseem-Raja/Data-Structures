#include <iostream>
using namespace std;
class Maxheap
{
    int size;

public:
    Maxheap(int size)
    {
        this->size = size;
    }
    void buildheap(int arr[])
    {
        for (int i = (this->size / 2) - 1; i >= 0; i--)
            maxheapify(arr, i, this->size);
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
            arr[i] = arr[largest];    //exchanging  largest value with arr[i]
            if (t == 1)
            {
                arr[left] = m;        
            }
            else if (t == 2)
                arr[right] = m;

            maxheapify(arr, largest, size);
        }
    }
    void heapsort(int arr[])
    {
        int sizee = this->size;
        buildheap(arr);
        cout << "heapsort:" << endl;
        for (int i = 0; i < sizee; i++)
        {
            int max = extract(arr);
            // size = this->size;
            cout << max << " ";
        }
    }
    int extract(int arr[])
    {

        int max = arr[0];
        arr[0] = arr[this->size - 1];
        this->size = this->size - 1;
        maxheapify(arr, 0, this->size);
        return max;
    }
    void display(int arr[])
    {

        for (int i = 0; i < this->size; i++)
            cout << arr[i] << " ";
    }
};
int main()
{

    int arr[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    Maxheap heapp(size);
    // heapp.buildheap(arr);
    // heapp.display(arr);
    // cout << endl;
    // int max = heapp.extract(arr);
    // cout << "Maximum element:" << max << endl;
    heapp.heapsort(arr);

    // heapp.display(arr);
}