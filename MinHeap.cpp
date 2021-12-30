#include <iostream>
using namespace std;
class Minheap
{
    int size;

public:
    Minheap(int size)
    {
        this->size = size;
    }
    int buildheap(int arr[])
    {
        for (int i = (this->size / 2) - 1; i >= 0; i--)
            minheapify(arr, i, this->size);
    }
    void minheapify(int arr[], int i,int size)
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
    void heapsort(int arr[])
    {
        int sizee=this->size;
        buildheap(arr);
        cout << "heapsort:" << endl;
        for (int i = 0; i < sizee; i++)
        {
            int min = extract(arr);
            // this->size = this->size-1;
            cout << min << " ";
        }
    }
    int extract(int arr[])
    {

        int min = arr[0];
        arr[0] = arr[this->size - 1];
        this->size = this->size - 1;
        minheapify(arr, 0, this->size);
        return min;
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
    Minheap heapp(size);
    // heapp.buildheap(arr);
    // heapp.display(arr);
    cout << endl;
    // int min = heapp.extract(arr);
    // --this->size;
    // cout << "Minimum element:" << min << endl;
    heapp.heapsort(arr);

    // heapp.display(arr);
}