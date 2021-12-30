//Find the "Kth" max and min element of an array given that all array elements are distinct.
#include <iostream>
using namespace std;
int main()
{

   int k,n=6;
    int arr[n] = {7 ,10, 4 ,3 ,20 ,15};

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = 0;
            if (arr[i] > arr[j])  //same we will  sort it in decending order to get the max one
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
        cout<<"Enter the element"<<endl;
        cin>>k;
        cout<<k<<"rd Smallest element is "<<arr[k-1]<<endl;
}
