//arrays insertion, traverse, delete ,search ,and update
#include <stdlib.h>
#include <iostream>
using namespace std;
int insert(int array[], int size)
{
    cout << "insert [" << size << "] elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}
int deletee(int z[], int y, int item)
{
    if (item < y && item >= 0)
    {
        int j = 0;
        if (j < y)
        {
            while (item < y - 1)
            {
                z[item] = z[item + 1];
                item++;
            }
            y = y - 1;
        }
        else
            y = y - 1;
    }
    else
    cout<<"enter the valid location"<<endl;
}
int searchh(int z[], int y, int item)
{
    int j = 0;
    while (j < y)
    {
        if (z[j] == item)
        {

            cout << "Found element at position " << j << endl;
            j = j + 1;
        }
        else
            cout << "element not found" << endl;
        break;
    }
}

int update(int z[], int y, int lo)
{
    if (lo< y && lo >= 0)
    {
        int g;
        cout << "enter the element " << endl;
        cin >> g;
        z[lo] = g;
    }
    else
        cout << "enter the valid location" << endl;
}
int display(int z[], int y)
{

    for (int i = 0; i < y; i++)
    {
        cout << z[i] << endl;
    }
}

int main()
{
    int count = 0;
    int size, c, item, el, yy, lo;
    cout << " Enter the size of  your array" << endl;
    cin >> size;
    int arr[size];
    insert(arr, size);
    while (1)
    {
        cout << "enter!! 0 for search !! 1 for delete !! 2 for update !!3 for display, 4 for exit" << endl;
        cin >> c;
        switch (c)
        {
        case 0:
            cout << "enter the element you want to search" << endl;
            cin >> item;
            searchh(arr, size, item);
            break;
        case 1:
            cout << "enter the location you want to delete" << endl;
            cin >> el;
            yy = deletee(arr, size, el);
            size = yy;

            break;
        case 2:
            cout << "enter the location you want to update" << endl;
            cin >> lo;
            update(arr, size, lo);
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
            exit(0);
            break;

        default:
            cout << "Enter the valid choice" << endl;
            break;
        }
    }
}