#include <iostream>
using namespace std;

int sort(int arr[], int size)
{
  int i, j = 0;
  while (j < size)
  {
    if (i == arr[j])
    {
      arr[i] = arr[j];
      arr[i]++;
    }
  }
  for (int i = 0; i < size; i++)
  {
    cout << arr[i];
  }
}
int main()
{
  int size;
  int arr[] = {0, 2, 0, 2, 1, 0};
  size = sizeof(arr) / sizeof(arr[0]);

  sort(arr, size);
}