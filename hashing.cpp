//OPEN ADDRESS HASHING(COLLUSION AVOIDANCE TECHNIQUES)
#include <iostream>
using namespace std;

class Hashing
{
    int size;
    int *arr;

public:
    Hashing(int size)
    {
        this->size = size;   //size of hashtable
        arr = new int[size]; //allocating size to hashtable
        for (int i = 0; i < this->size; i++)
            arr[i] = -1; //initializing all locations as -ve that means they are empty
    }
    void linearprobing(int key) //Linear probing
    {
        int i = 0;
        int index = key % this->size;
        while (i != this->size)
        {
            if (arr[index] == -1)
            {
                arr[index] = key;
                break;
            }
            else
            {
                i++;
                index = (++index) % this->size;
            }
        }
    }
    void quadraticprobing(int key)
    {
        int i = 0;
        int a = 1, b = 3;
        // int index = ((key % this->size) + (a * i) + (b * (i * i))) % this->size;
        int index = (key % this->size);
        while (i != this->size)
        {
            if (arr[index] == -1)
            {
                arr[index] = key;
                break;
            }
            else
            {
                i++;
                index = ((key % this->size) + (a * i) + (b * (i * i))) % this->size;
            }
        }
    }

    void doublehashing(int key)
    {
        int i = 0;
        int index1 = key % this->size;
        int index2 = 1 + (key % (this->size - 1));
        int newIndex = index1;
        while (i != this->size)
        {
            if (arr[newIndex] == -1)
            {
                arr[newIndex] = key;
                break;
            }
            else
            {
                i++;
                newIndex = (index1 + i * index2) % this->size;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << "At index->  " << i << "      "
                 << "key: " << arr[i] << endl;
        }
    }
};
int main()
{
    Hashing hashtable(11);
    hashtable.quadraticprobing(10);
    hashtable.quadraticprobing(22);
    hashtable.quadraticprobing(31);
    hashtable.quadraticprobing(4);
    hashtable.quadraticprobing(15);
    hashtable.quadraticprobing(28);
    hashtable.quadraticprobing(17);
    hashtable.quadraticprobing(88);
    hashtable.quadraticprobing(59);
    //      hashtable.linearprobing(4);
    hashtable.display();
}