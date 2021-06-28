//When we do multiplication:
//The number of columns of the 1st matrix must equal the number of rows of the 2nd matrix.
//And the result will have the same number of rows as the 1st matrix, and the same number
//of columns as the 2nd matrix.
#include <iostream>
using namespace std;

// int main()
// {

//     int arr1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

//     int product[3][3];
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             product[i][j]=0;
//             for (int k = 0; k < 3; k++)
//             {
//                 product[i][j] += arr1[j][k] * arr2[k][i];
//             }
//         }
//     }
//         for (int i = 0; i < 3; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 cout << product[i][j] <<",";
//             }
//             cout<<endl;
//         }

// }
class arrays
{
    int rowsize;
    int colsize;
    int mat[0][0];

public:
    arrays(int rowsize, int colsize)
    {
        rowsize = rowsize;
        colsize = colsize;
        mat[rowsize][colsize];
    }
    void insertElement(int element)
    {
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
            {
                cin >> mat[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0; i < rowsize; i++)
        {
            for (int j = 0; j < colsize; j++)
            {
                cout << mat[i][j]<<"  ";
            }
        }
    }
};

int main()
{
    int rowsize, colsize, element;
    cout << "Enter the rowsize and colsize of first matrix" << endl;
    cin >> rowsize >> colsize;
    arrays obj1(rowsize, colsize);
    cout << "Enter the elements of first matrix" << endl;
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            obj1.insertElement(element);
        }
    }
    obj1.display();
    cout << "Enter the rowsize and colsize of second matrix" << endl;
    cin >> rowsize >> colsize;
    arrays obj2(rowsize, colsize);
    cout << "Enter the elements of second matrix" << endl;
    for (int i = 0; i < rowsize; i++)
    {
        for (int j = 0; j < colsize; j++)
        {
            obj2.insertElement(element);
        }
    }
    obj2.display();
}