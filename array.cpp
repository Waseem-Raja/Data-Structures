//arrays insertion, traverse, delete ,search ,and update
/*#include <stdlib.h>
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
}*/
#include <iostream>
#include <limits.h>

class ArrayList
{
    int *arr;
    int len;
    int size;

public:
    ArrayList()
    {
        this->arr = NULL;
        this->len = 0;
        this->size = 0;
    }

    ArrayList(int size)
    {
        this->size = size;
        this->arr = new int[this->size];
        this->len = 0;
    }

    bool add(int element)
    {
        int *tempPtr = nullptr;
        //this will run when array will be full in any case, which means len and size would be same
        if (this->len == this->size)
        {
            tempPtr = new int[size + 1];
            tempPtr[len] = element;
            //++this->len;
            // at first this willl not run, because at first arr will contine nullptr
            if (arr != nullptr)
            {
                for (int i = 0; i < this->len; ++i)
                {
                    tempPtr[i] = arr[i];
                }
                delete[] this->arr; // deleting old array after copying the old elements to new array , so we dont need old arrray
                                    // now, we need to copy the new array address to "arr" array pointer
            }
            this->arr = tempPtr;
            ++this->len;
            ++this->size;
            return true;
        }
        else
        { // else if the size and len are not equal that means we have vacant location left to put element in , or we have space to store elements
            arr[len] = element;
            ++this->len;
            return true;
        }
        return true;
    }

    int linearSearch(int element)
    {
        for (int i = 0; i < this->len; i++)
        {
            if (this->arr[i] == element)
            {
                return i;
            }
        }
        return -1;
    }

    bool update(int index, int element)
    {
        if (index >= 0 && index < size)
        {
            this->arr[index] = element;
            return true;
        }
        return false;
    }

    int get(int position)
    {
        if (position >= 0 && position < len)
        {
            return arr[position];
        }
        return -1; // -1 represents that the index was invalid
    }

    bool remove(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < this->size - 1; ++i)
            {
                this->arr[i] = this->arr[i + 1];
            }
            this->len--;
            return true;
        }
        return false;
    }

    int length()
    {
        return this->len;
    }

    int min()
    {
        int min_element = INT_MAX;

        for (int i = 0; i < this->len; ++i)
        {
            if (this->arr[i] < min_element)
                min_element = this->arr[i];
        }
        return min_element;
    }

    int max()
    {
        int max_el = INT_MIN;

        for (int i = 0; i < this->len; ++i)
        {
            if (this->arr[i] > max_el)
                max_el = this->arr[i];
        }

        return max_el;
    }

    int shiftLeft(bool forRotation = false)
    {
        int overFlowEl = 0;
        if (len > 1)
        {
            overFlowEl = this->arr[0];
            for (int i = 0; i < this->len - 1; ++i)
            {
                this->arr[i] = this->arr[i + 1];
            }

            this->arr[len - 1] = 0;
            if (!forRotation)
                this->len--;
        }
        else if (this->len == 1)
        {
            overFlowEl = this->arr[0];
            this->arr[0] = 0;
            if (!forRotation)
                this->len--;
        }
        else
        {
            return -1;
        }

        return overFlowEl;
    }

    int shiftRight()
    {
        int overFlowEl = 0;
        if (len > 1)
        {
            overFlowEl = this->arr[this->len - 1];

            for (int i = this->len - 1; i > 0; --i)
            {
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[0] = 0;
        }
        else if (this->len == 1)
        {
            this->arr[1] = this->arr[0];
            this->len++;
        }
        else
        {
            return -1; //
        }
        return overFlowEl;
    }

    void rotateLeft()
    {
        if (this->len > 0)
        {
            //int a = this->shiftLeft(true);
            this->arr[this->len - 1] = this->shiftLeft(true);
        }
    }

    void rotateRight()
    {
        if (this->len > 0)
        {
            //int a = this->shiftLeft(true);
            this->arr[0] = this->shiftRight();
        }
    }

    void reverse()
    {
        if (this->len > 1)
        {
            int i = 0;
            int j = len - 1;
            int temp = 0;
            while (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                ++i;
                --j;
            }
        }
    }
};

int main()
{
    ArrayList kaiser(5);
    for (int i = 5; i >= 1; --i)
    {
        kaiser.add(i);
    }

    //kaiser.remove(1);

    //std::cout<<"Over FLow Elmemnt : "<< kaiser.shiftRight()<<"\n";
    // kaiser.rotateRight();
    kaiser.reverse();
    for (int i = 0; i < kaiser.length(); i++)
    {
        std::cout << kaiser.get(i) << "\n";
    }

    //std::cout<<"Minimum is : "<<kaiser.min()<<"\n";

    return 0;
}