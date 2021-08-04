#include <iostream>
using namespace std;

int main()
{

  // int size = 0;
  // int len = 3;
  // int arr[size];
  // while (2<len)
  // {
  //     cout << "Enter the element" << endl;
  //     cin >> arr[size];
  //     size++;
  //     cout<<"want to stop enter 1 if continue enter 3"<<endl;
  //     cin>>len;
  // }
  // for (int i = 0; i < size; i++)
  // {
  //   cout<<arr[i];
  // }

  int n = 5;

  int arr[n] = {1, 2, 3, -2, 5};

  int sum = 0;
  for (int i = 0; i < n; i++)
  {
       sum=sum+arr[i]; 
  }
  cout << sum;
}