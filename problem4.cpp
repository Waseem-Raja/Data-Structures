#include <iostream>
using namespace std;

int main()
{
    int n = 8;
    int arr[] = {3, 4, -5, 3, 5, -5, 6, -9};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            if (arr[i] < arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return(0);
}