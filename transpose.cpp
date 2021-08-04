#include <iostream>
using namespace std;

int main()
{
    int rowsize, colsize;
    cout << "Enter the dimensions rowsize and colsize of your matrix" << endl;
    cin >> rowsize >> colsize;
    int arr[rowsize][colsize];
    int arr2[colsize][rowsize];
    if (rowsize >= 1 && colsize >= 1)
    {
        cout << "Enter the elements of your matrix" << endl;
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
            {
                arr2[j][i] = arr[i][j];
            }
        }

        for (int i = 0; i < colsize; i++)
        {
            for (int j = 0; j < rowsize; j++)
            {
                cout << arr2[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Enter the correct dimensions" << endl;
}