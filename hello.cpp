/ C++ program to merge two sorted arrays/
#include <iostream>
using namespace std;
#include <fstream>

void mergee(int arr1[], int arr2[], int x, int y, int arr3[])
{
  int i = 0, j = 0, k = 0;
  while (i < x && j < y)
  {

    if (arr1[i] < arr2[j])

      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < x)
    arr3[k++] = arr1[i++];

  while (j < y)
    arr3[k++] = arr2[j++];
}
