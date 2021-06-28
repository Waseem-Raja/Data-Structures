//When we do multiplication:
//The number of columns of the 1st matrix must equal the number of rows of the 2nd matrix.
//And the result will have the same number of rows as the 1st matrix, and the same number
//of columns as the 2nd matrix.
#include <iostream>
using namespace std;

int main()
{

    int rowsize1, colsize1, rowsize2, colsize2;
    cout << "Enter the dimensions rowsize and colsize of your first matrix" << endl;
    cin >> rowsize1 >> colsize1;
    int arr1[rowsize1][colsize1];
    cout << "Enter the dimensions rowsize and colsize of your second matrix" << endl;
    cin >> rowsize2 >> colsize2;
    int arr2[rowsize2][colsize2];
    int product[rowsize1][colsize2];
    if (colsize1 == rowsize2)
    {
        cout << "Enter the elements of your first matrix" << endl;
        for (int i = 0; i < rowsize1; i++)
        {
            for (int j = 0; j < colsize1; j++)
            {
                cin >> arr1[i][j];
            }
        }
        cout << "Enter the elements of your second matrix" << endl;
        for (int i = 0; i < rowsize2; i++)
        {
            for (int j = 0; j < colsize2; j++)
            {

                cin >> arr2[i][j];
            }
        }
        for (int i = 0; i < rowsize1; i++)
        {
            for (int j = 0; j < colsize2; j++)
            {
                product[i][j] = 0;
                for (int k = 0; k < colsize1; k++)
                {
                    product[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        cout << "Multiplication :" << endl;
        for (int i = 0; i < rowsize1; i++)
        {
            for (int j = 0; j < colsize2; j++)
            {
                cout << product[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Enter the correct dimensions" << endl;
}